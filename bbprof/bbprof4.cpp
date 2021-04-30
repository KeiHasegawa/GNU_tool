#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <cassert>
#include <bfd.h>
#include <dis-asm.h>

extern "C" int print_insn_i386(bfd_vma pc, disassemble_info *info);

struct app_data {
  bfd_vma m_prof_addr;
  std::vector<std::pair<bfd_vma, bfd_vma>>* m_result;
  bfd_vma m_caller;
  bfd_vma m_prev;
  bfd_vma m_last_ret;
};

namespace my_fprintf_data {
  char* last;
} // end of namespace my_fprintf_data

struct find_caller1 {
  bfd_vma m_sec_base;
  disassemble_info* m_info;
  find_caller1(bfd_vma sec_base, disassemble_info* info)
    : m_sec_base{sec_base}, m_info{info} {}
  bool operator()(asymbol* sym, bfd_vma end)
  {
    using namespace std;
#ifdef JUST_DISASSEMBLE
    cout << sym->name << ':' << endl;
#endif
    auto p = reinterpret_cast<app_data*>(m_info->application_data);
    p->m_caller = m_sec_base + sym->value;
    auto res = p->m_result;
    int n = res->size();
    const char* ret = "ret";
    int len = strlen(ret);

    while (p->m_caller != end) {
      int n = print_insn_i386(p->m_caller, m_info);
      p->m_prev = p->m_caller;
      if (!strncmp(my_fprintf_data::last, ret, len)) 
	p->m_last_ret = p->m_caller;
      p->m_caller += n;
#ifdef JUST_DISASSEMBLE
      cout << endl;
#endif
    }
    if (n != res->size()) {
      assert(!res->empty());
      auto& second = res->back().second;
      assert(!second);
      assert(my_fprintf_data::last);
      if (strncmp(my_fprintf_data::last, ret, len))
	second = p->m_last_ret;
      else
	second = p->m_prev;
    }
    return true;
  }
};

int my_fprintf(void* p, const char* fmt, ...)
{
  using namespace std;
  va_list ap;
  va_start(ap, fmt);
  for (char c = *fmt ; c ; c = *++fmt) {
    if (c == '%') {
      c = *++fmt;
      switch (c) {
      case 's':
	my_fprintf_data::last = va_arg(ap, char*);
	break;
      case 'x': case 'd': case 'i': case 'c':
	va_arg(ap, int);
	break;
      case 'l':
	{
	  c = *++fmt;
	  switch (c) {
	  case 'x': case 'd':
	    va_arg(ap, long);
	    break;
	  case 'l':
	    ++fmt;
	    va_arg(ap, long long);
	    break;
	  }
	}
      case '%':
	break;
      default:
	// asm("int3");
	break;
      }
    }
  }
  va_end(ap);
  return 0;
}

void my_address_func(bfd_vma addr, disassemble_info* info)
{
  if (!my_fprintf_data::last)
    return;
  const char* call = "call";
  int len = strlen(call);
  if (strncmp(my_fprintf_data::last, call, len))
    return;
  auto p = reinterpret_cast<app_data*>(info->application_data);
  auto prof_addr = p->m_prof_addr;
  if (addr != prof_addr)
    return;
  auto res = p->m_result;
  if (!res->empty()) {
    auto& second = res->back().second;
    if (!second) {
      auto prev = p->m_prev;
      second = prev;
    }
  }
  auto caller = p->m_caller;
  using namespace std;
  res->push_back(make_pair(caller,0));
}

void find_caller(bfd* abfd, asection* sect, asymbol** syms, int nsyms,
		 bfd_vma prof_addr,
		 std::vector<std::pair<bfd_vma, bfd_vma>>& res)
{
  using namespace std;
  auto flags = sect->flags;
  if (!(flags & SEC_CODE))
    return;

  vector<asymbol*> vs;
  copy_if(&syms[0], &syms[nsyms], back_inserter(vs),
	  [sect](asymbol* p){ return p->section == sect; } );
  if (vs.empty())
    return;

  sort(begin(vs), end(vs),
       [](asymbol* x, asymbol* y){ return x->value < y->value; });

  disassemble_info info;
#ifdef JUST_DISASSEMBLE
  init_disassemble_info(&info, stdout, (fprintf_ftype)fprintf);
#else
  init_disassemble_info(&info, 0, my_fprintf);
  info.print_address_func = my_address_func;
#endif
#ifdef __x86_64__
  info.mach = bfd_mach_x86_64;
#else // __x86_64__
  info.mach = bfd_mach_i386_i386;
#endif // __x86_64__
  app_data data = { prof_addr, &res };
  info.application_data = reinterpret_cast<void*>(&data);

  bfd_byte *buf;
  if (!bfd_malloc_and_get_section(abfd, sect, &buf)) {
    cerr << "bfd_malloc_and_get_section failed" << endl;
    return;
  }
  unique_ptr<bfd_byte> sweeper(buf);
  info.buffer = buf;
  size_t size = sect->size;
  info.buffer_length = size;
  bfd_vma sec_base = sect->vma;
  info.buffer_vma = sec_base;

  vector<bfd_vma> va;
  transform(begin(vs)+1, end(vs), back_inserter(va),
	    [sec_base](asymbol* p){ return sec_base + p->value; });
  va.push_back(sec_base + size);
  mismatch(begin(vs), end(vs), begin(va), find_caller1(sec_base, &info));
}

void debug(const std::vector<std::pair<bfd_vma, bfd_vma>>& v)
{
  using namespace std;
  cout << hex;
  for (auto addr : v)
    cout << addr.first << " - " << addr.second << endl;
}

int main(int argc, char** argv)
{
  using namespace std;
  if (argc != 2) {
    cerr << "usage % " << argv[0] << " a.out" << endl;
    return 1;
  }

  bfd* abfd =  bfd_openr(argv[1], 0);
  if (!abfd) {
    cerr << "bfd_openr(" << argv[1] << ") failed" << endl;
    return 1;
  }

  if (!bfd_check_format(abfd, bfd_object)) {
    cerr << "bfd_check_format failed" << endl;
    return 1;
  }

  struct sweeper {
    bfd* m_bfd;
    sweeper(bfd* b) : m_bfd{b} {}
    ~sweeper(){ bfd_close(m_bfd); }
  } sweeper(abfd);

  int upper =  bfd_get_symtab_upper_bound(abfd);
  if (upper < 0) {
    cerr << "bfd_get_symtab_upper_bound failed" << endl;
    return 1;
  }

  asymbol** syms = (asymbol**)(new char[upper]);
  unique_ptr<asymbol*> sweeper2(syms);
  int nsyms = bfd_canonicalize_symtab(abfd, syms);
  if (nsyms < 0) {
    cerr << "bfd_canonicalize_symtab failed" << endl;
    return 1;
  }

  string fn = "_profile_basic_block_";
  auto it = find_if(&syms[0], &syms[nsyms],
		    [fn](asymbol* p){ return p->name == fn; });
  if (it == &syms[nsyms]) {
    cerr << '`' << fn << "' not found" << endl;
    return 1;
  }
  asymbol* sym = *it;
  asection* sect = sym->section;
  bfd_vma prof_addr = sect->vma + sym->value;

  vector<pair<bfd_vma, bfd_vma>> res;
  for (asection* sect = abfd->sections ; sect ; sect = sect->next)
    find_caller(abfd, sect, syms, nsyms, prof_addr, res);

  debug(res);
  return 0;
}
