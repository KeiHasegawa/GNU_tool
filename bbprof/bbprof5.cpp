#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <unistd.h>
#include <bfd.h>
#include <dis-asm.h>

int read_bb(const char* bbout, std::set<bfd_vma>& res)
{
  using namespace std;
  ifstream ifs{bbout};
  if (!ifs) {
    cerr << "cannot open " << bbout << endl;
    return -1;
  }
  while (1) {
    union {
      bfd_vma addr;
      char c[sizeof addr];
    };
    ifs.read(&c[0], sizeof c);
    if (ifs.eof())
      return 0;
    res.insert(addr);
  }
}

extern "C" int print_insn_i386(bfd_vma pc, disassemble_info *info);

struct app_data {
  bfd_vma m_prof_addr;
  std::map<bfd_vma, bfd_vma>* m_result;
  bfd_vma m_caller;
  bfd_vma m_prev;
  bfd_vma m_last_ret;
};

namespace my_fprintf_data {
  char* last;
} // end of namespace my_fprintf_data

struct create_bb1 {
  bfd_vma m_sec_base;
  disassemble_info* m_info;
  create_bb1(bfd_vma sec_base, disassemble_info* info)
    : m_sec_base{sec_base}, m_info{info} {}
  bool operator()(asymbol* sym, bfd_vma end)
  {
    using namespace std;
#ifdef __CYGWIN__
    if (!strcmp(sym->name, "__CTOR_LIST__"))
      return false;
#endif
    auto p = reinterpret_cast<app_data*>(m_info->application_data);
    p->m_caller = m_sec_base + sym->value;
    auto res = p->m_result;
    int before = res->size();
    const char* ret = "ret";
    int len = strlen(ret);
    while (p->m_caller != end) {
      int n = print_insn_i386(p->m_caller, m_info);
      p->m_prev = p->m_caller;
      if (my_fprintf_data::last && !strncmp(my_fprintf_data::last, ret, len)) 
	p->m_last_ret = p->m_caller;
      p->m_caller += n;
    }
    if (before != res->size()) {
      assert(!res->empty());
      auto it = res->rbegin();
      auto& second = it->second;
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
  using namespace std;
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
  auto caller = p->m_caller;
  auto res = p->m_result;
  res->insert(make_pair(caller+5,0));  // +5 means next instrunction
}

void create_bb(bfd* abfd, asection* sect, asymbol** syms, int nsyms,
	       bfd_vma prof_addr, std::map<bfd_vma, bfd_vma>& res)
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
  init_disassemble_info(&info, 0, my_fprintf);
  info.print_address_func = my_address_func;
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
  mismatch(begin(vs), end(vs), begin(va), create_bb1(sec_base, &info));
}

namespace roff {
  const char* br = ".br";
  const char* fB = "\\fB";
  const char* fR = "\\fR";
} // end of namespace roff

inline bool out_fB(bool prev_highlight, std::ifstream& ifs)
{
#ifdef __CYGWIN__
  if (!prev_highlight)
    return false;
  if (ifs.peek() != '\r')
    return true;
  ifs.get();
  return ifs.peek() != '\n';
#else // __CYGWIN__
  return prev_highlight && ifs.peek() != '\n';
#endif // __CYGWIN__
}

inline void output_newline()
{
  using namespace std;
#ifdef __CYGWIN__
  cout << "\r\n" << roff::br << "\r\n";
#else // __CYGWIN__
  cout << '\n' << roff::br << '\n';
#endif // __CYGWIN__
}

inline bool unexpected_eof(const char* file)
{
  using namespace std;
  cerr << "unexpected EOF at `" << file << "''\n";
  return true;
}

struct info_t {
  bfd_vma addr;
  bool highlight;
  const char* file;
  const char* func;
  unsigned int line;
  unsigned int column;
  unsigned int disc;
};

inline bool operator<(const info_t& x, const info_t& y)
{
  if (int n = strcmp(x.file, y.file))
    return n < 0;

  if (x.line < y.line)
    return true;
  if (x.line > y.line)
    return false;

  if (x.column < y.column)
    return true;
  if (x.column > y.column)
    return false;

  return x.disc < y.disc;
}

inline bool match(const std::set<bfd_vma>& addrs, bfd_vma y)
{
#ifdef __CYGWIN__
  using namespace std;
  auto p = find_if(begin(addrs), end(addrs),
		   [y](bfd_vma x){ return (x & 0xffff) == (y & 0xffff); });
  return p != end(addrs);
#else // __CYGWIN__
  return addrs.find(y) != addrs.end();
#endif // __CYGWIN__
}

inline bool match(const info_t& x, const std::set<std::string>& ex)
{
  using namespace std;
  string fn = x.file;
  auto p = find_if(begin(ex), end(ex),
		   [fn](string s){ return s == fn.substr(0, s.length()); });
  return p != end(ex);
}

extern "C"
bfd_boolean my_func(bfd *abfd,
		    asymbol **symbols,
		    asection *section,
		    bfd_vma offset,
		    const char **filename_ptr,
		    const char **functionname_ptr,
		    unsigned int *line_ptr,
		    unsigned int *column_ptr,
		    unsigned int *discriminator_ptr);

inline bool collect1(bfd* abfd, asection* sect, asymbol** syms, info_t* res)
{
  using namespace std;
  auto flags = sect->flags;
  if (!(flags & SEC_ALLOC))
    return false;

  bfd_vma addr = res->addr;
  bfd_vma vma = sect->vma;
  if (addr < vma)
    return false;

  size_t size = sect->size;
  if (addr >= vma + size)
    return false;

  auto ret = my_func(abfd, syms, sect, addr - vma, &res->file, &res->func,
		     &res->line, &res->column, &res->disc);
  if (!ret) {
    cerr << hex << addr << " not found" << endl;
    return true;
  }
  return true;
}

inline info_t collect(bfd* abfd, asymbol** syms,
		      bfd_vma addr, bool highlight)
{
  info_t res = { addr, highlight };
  for (asection* sect = abfd->sections ; sect ; sect = sect->next) {
    if (collect1(abfd, sect, syms, &res))
      return res;
  }
  return res;
}

inline void tail(std::ifstream& ifs)
{
  using namespace std;
  while (1) {
    int c = ifs.get();
    if (ifs.eof())
      return;
    cout.put(c);
  }
}

std::unique_ptr<std::ifstream> ptr_ifs;

inline bool output(const info_t& info)
{
  using namespace std;
  const char* file = info.file;
  const char* func = info.func;
  unsigned int line = info.line;
  unsigned int column = info.column;
  bool highlight = info.highlight;

  static const char* prev_file;
  static const char* prev_func;
  static unsigned int prev_line, prev_column;
  static bool prev_highlight;
  if (!prev_file || strcmp(prev_file, file)) {
    if (prev_file) {
      tail(*ptr_ifs.get());
      output_newline();
      output_newline();
      prev_highlight = false;
    }
#ifdef __CYGWIN__
    cout << file << "\r\n";
#else
    cout << file << '\n';
#endif
    output_newline();
    prev_file = file;
    prev_func = func;
    prev_line = line;
    --line;
    prev_column = column;
    ptr_ifs.reset(new ifstream {file});
  }
  else {
    unsigned int tmp = line;
    assert(prev_line <= line);
    line -= prev_line;
    prev_line = tmp;
    if (line)
      prev_column = column;
    else {
      tmp = column;
      assert(prev_column <= column);
      column -= prev_column;
      prev_column = tmp;
    }
    assert(func);
    if (strcmp(prev_func, func))
      prev_highlight = false;
    prev_func = func;
  }

  auto& ifs = *ptr_ifs.get();
  if (!ifs) {
    if (ifs.eof())
      return true;  // already error message outputed
    cerr << "cannot open " << file << endl;
    return true;
  }

  while (line--) {
    bool b = out_fB(prev_highlight, ifs);
    if (b)
      cout << roff::fB;
    while (1) {
      int c = ifs.get();
      if (ifs.eof())
	return unexpected_eof(file);
      if (c == '\r')
	c = ifs.get();
      if (c == '\n')
	break;
      if (c == ' ' || c == '\t' || c == '\\')  // not support SJIS JIS
	cout.put('\\');
      cout.put(c);
    }
    if (b)
      cout << roff::fR;
    output_newline();
  }

  if (!column)
    return true;

  bool b = prev_highlight && column != 1;
  if (b)
    cout << roff::fB;

  while (--column) {
    int c = ifs.get();
    if (ifs.eof())
      return unexpected_eof(file);
    if (c == ' ' || c == '\t' || c == '\\')  // not support SJIS JIS
      cout.put('\\');
    cout.put(c);
  }

  if (b)
    cout << roff::fR;

  if (highlight)
    cout << roff::fB;
  {
    int c = ifs.get();
    if (ifs.eof())
      return unexpected_eof(file);
    cout.put(c);
  }
  if (highlight)
    cout << roff::fR;

  prev_highlight = highlight;
  return true;
}

int main(int argc, char** argv)
{
  using namespace std;
  set<string> ex;
  while (getopt(argc, argv, "e:") != -1) {
    ex.insert(optarg);
    argc -= 2;
  }

  if (argc != 3) {
    cerr << "usage % " << argv[0] << " a.out bb.out" << endl;
    return 1;
  }

  set<bfd_vma> trace_points;
  if (read_bb(argv[optind+1], trace_points) < 0)
    return 1;

  bfd* abfd =  bfd_openr(argv[optind], 0);
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

  map<bfd_vma, bfd_vma> bb;
  for (asection* sect = abfd->sections ; sect ; sect = sect->next)
    create_bb(abfd, sect, syms, nsyms, prof_addr, bb);

  vector<info_t> info;
  for (auto p : bb) {
    bfd_vma addr = p.first;
    bool hightlight = match(trace_points, addr);
    info.push_back(collect(abfd, syms, addr, hightlight));
    if (addr = p.second)
      info.push_back(collect(abfd, syms, addr, hightlight));
  }
  remove_if(begin(info), end(info),
	    [&ex](const info_t& x){ return match(x,ex); });
  sort(begin(info), end(info));

  for_each(begin(info), end(info), output);

  tail(*ptr_ifs.get());

  return 0;
}

using namespace std;
void debug(const set<bfd_vma>& s)
{
  cout << hex;
  for (auto p : s)
    cout << p << endl;
}

void debug(const map<bfd_vma, bfd_vma>& m)
{
  cout << hex;
  for (auto p : m)
    cout << p.first << " - " << p.second << endl;
}

void debug(const info_t& p)
{
  cout << hex << p.addr << ',';
  cout << p.highlight << ',';
  cout << p.file << ',';
  if (p.func)
    cout << p.func << ',';
  else
    cout << "null" << ',';
  cout << dec;
  cout << p.line << ',';
  cout << p.column << ',';
  cout << p.disc << endl;
}

void debug(const vector<info_t>& info)
{
  for (auto p : info)
    debug(p);
}
