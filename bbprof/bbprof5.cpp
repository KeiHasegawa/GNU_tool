#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#ifdef __CYGWIN__
// Not refer to dll
extern "C" {
  int getopt(int, char**, const char*);
  extern char* optarg;
  extern int optind;
}
#else // __CYGWIN__
#include <unistd.h>
#endif // __CYGWIN__
#include <bfd.h>
#include <dis-asm.h>
#include "my_dwarf2.h"

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
  bool operator()(bfd_symbol* sym, bfd_vma end)
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

void create_bb(bfd* abfd, asection* sect, bfd_symbol** syms, int nsyms,
	       bfd_vma prof_addr, std::map<bfd_vma, bfd_vma>& res)
{
  using namespace std;
  auto flags = sect->flags;
  if (!(flags & SEC_CODE))
    return;

  vector<bfd_symbol*> vs;
  copy_if(&syms[0], &syms[nsyms], back_inserter(vs),
	  [sect](bfd_symbol* p){ return p->section == sect; } );
  if (vs.empty())
    return;

  sort(begin(vs), end(vs),
       [](bfd_symbol* x, bfd_symbol* y){ return x->value < y->value; });

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
	    [sec_base](bfd_symbol* p){ return sec_base + p->value; });
  va.push_back(sec_base + size);
  mismatch(begin(vs), end(vs), begin(va), create_bb1(sec_base, &info));
}

namespace roff {
  const char* br = ".br";
  const char* fB = "\\fB";
  const char* fR = "\\fR";
} // end of namespace roff

inline bool comp_line(line_info* p, int line)
{
  return p->line == line;
}

inline bool out_fB1(int curr, line_sequence* seq, int index, int prev_index)
{
  using namespace std;
  if (!index)
    return true;
  auto array = seq->line_info_lookup;
  int m = min(index-1, prev_index+1);
  auto p = find_if(&array[m], &array[index],
		   bind2nd(ptr_fun(comp_line), curr));
  return p != &array[index];
}

inline bool out_fB(bool prev_highlight, std::ifstream& ifs,
		   int curr, line_sequence* seq, int index, int prev_index)
{
  if (!prev_highlight)
    return false;
#ifdef __CYGWIN__
  if (ifs.peek() != '\r')
    return out_fB1(curr, seq, index, prev_index);
  ifs.get();
#endif // __CYGWIN__
  if (ifs.peek() == '\n')
    return false;
  return out_fB1(curr, seq, index, prev_index);
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

inline void unexpected_eof(const char* file)
{
  using namespace std;
  cerr << "unexpected EOF at `" << file << "''\n";
}

struct info_t {
  bfd_vma addr;
  bool highlight;
  line_sequence* seq;
  int index;
  const char* func;
};

inline bool operator<(const info_t& x, const info_t& y)
{
  auto xi = x.seq->line_info_lookup[x.index];
  auto yi = y.seq->line_info_lookup[y.index];
  if (int n = strcmp(xi->filename, yi->filename))
    return n < 0;
  
  if (xi->line < yi->line)
    return true;
  if (xi->line > yi->line)
    return false;

  if (xi->column < yi->column)
    return true;
  if (xi->column > yi->column)
    return false;

  return xi->discriminator < yi->discriminator;
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

inline bool match(std::string fn, const std::set<std::string>& ex)
{
  using namespace std;
  auto p = find_if(begin(ex), end(ex),
		   [fn](string s){ return s == fn.substr(0, s.length()); });
  return p != end(ex);
}

extern "C"
bfd_boolean my_func(bfd *abfd,
		    bfd_symbol **symbols,
		    asection *section,
		    bfd_vma offset,
		    line_sequence** seq,
		    int* index,
		    const char **func);

inline bool collect1(bfd* abfd, asection* sect, bfd_symbol** syms, info_t* res)
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

  line_sequence* seq;
  int index;
  auto ret = my_func(abfd, syms, sect, addr - vma,
		     &res->seq, &res->index, &res->func);
  if (!ret) {
    cerr << hex << addr << " not found" << endl;
    return true;
  }
  return true;
}

inline info_t collect(bfd* abfd, bfd_symbol** syms,
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

inline void output1(int c)
{
  using namespace std;
  if (c == ' ' || c == '\t' || c == '-' || c == '\\')  // not support SJIS JIS
    cout.put('\\');
  cout.put(c);
}

inline void output(const info_t& info)
{
  using namespace std;
  auto p = info.seq->line_info_lookup[info.index];
  const char* file = p->filename;
  const char* func = info.func;
  unsigned int line = p->line;
  unsigned int column = p->column;
  bool highlight = info.highlight;

  static const char* prev_file;
  static const char* prev_func;
  static unsigned int prev_line, prev_column;
  static bool prev_highlight;
  static int prev_index;
  if (!prev_file || strcmp(prev_file, file)) {
    if (prev_file) {
      tail(*ptr_ifs.get());
      output_newline();
      output_newline();
      prev_highlight = false;
    }
    else {
      cout << ".char \\- \\N'45'\n";
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
    prev_index = info.index;
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
      return;  // already error message outputed
    cerr << "cannot open " << file << endl;
    return;
  }

  while (line--) {
    int curr = prev_line - line - 1;
    auto seq = info.seq;
    auto index = info.index;
    bool b = out_fB(prev_highlight, ifs, curr, seq, index, prev_index);
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
      output1(c);
    }
    if (b)
      cout << roff::fR;
    output_newline();
  }

  if (!column)
    return;

  bool b = prev_highlight && column != 1;
  if (b)
    cout << roff::fB;

  while (--column) {
    int c = ifs.get();
    if (ifs.eof())
      return unexpected_eof(file);
    output1(c);
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
  prev_index = info.index;
}

inline void usage(const char* prog)
{
  using namespace std;
  cerr << "usage % " << prog << " [-e dir][-h] a.out bb.out" << endl;
}

inline const char* get_fn(const info_t& x)
{
  return x.seq->line_info_lookup[x.index]->filename;
}

inline bool is_header(const char* fn)
{
  int len = strlen(fn);
  if (len < 2)
    return false;
  if (fn[len-2] != '.')
    return false;
  return fn[len-1] == 'h';
}

int main(int argc, char** argv)
{
  using namespace std;
  bool exclude_header = false;
  set<string> ex;
  for ( int ret; (ret = getopt(argc, argv, "e:h")) != -1 ; ) {
    switch (ret) {
    case 'e':
      ex.insert(optarg);
      break;
    case 'h':
      exclude_header = true;
      break;
    default:
      usage(argv[0]);
      return 1;
    }
  }

  if (argc - optind != 2) {
    usage(argv[0]);
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

  struct sweeper {
    bfd* m_bfd;
    sweeper(bfd* b) : m_bfd{b} {}
    ~sweeper(){ bfd_close(m_bfd); }
  } sweeper(abfd);

  if (!bfd_check_format(abfd, bfd_object)) {
    cerr << "bfd_check_format failed" << endl;
    return 1;
  }

  int upper =  bfd_get_symtab_upper_bound(abfd);
  if (upper < 0) {
    cerr << "bfd_get_symtab_upper_bound failed" << endl;
    return 1;
  }

  bfd_symbol** syms = (bfd_symbol**)(new char[upper]);
  unique_ptr<bfd_symbol*> sweeper2(syms);
  int nsyms = bfd_canonicalize_symtab(abfd, syms);
  if (nsyms < 0) {
    cerr << "bfd_canonicalize_symtab failed" << endl;
    return 1;
  }

  string fn = "_profile_basic_block_";
  auto it = find_if(&syms[0], &syms[nsyms],
		    [fn](bfd_symbol* p){ return p->name == fn; });
  if (it == &syms[nsyms]) {
    cerr << '`' << fn << "' not found" << endl;
    return 1;
  }
  bfd_symbol* sym = *it;
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
  auto p = remove_if(begin(info), end(info),
		     [&ex](const info_t& x){ return match(get_fn(x), ex); });
  info.erase(p, end(info));
  if (exclude_header) {
    auto p = remove_if(begin(info), end(info),
		       [](const info_t& x){ return is_header(get_fn(x)); });
    info.erase(p, end(info));
  }
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
  auto q = p.seq->line_info_lookup[p.index];
  cout << q->filename << ',';
  if (p.func)
    cout << p.func << ',';
  else
    cout << "null" << ',';
  cout << dec;
  cout << q->line << ',';
  cout << q->column << ',';
  cout << q->discriminator << endl;
}

void debug(const vector<info_t>& info)
{
  for (auto p : info)
    debug(p);
}

#include <iterator>

void debug(const set<string>& s)
{
  copy(begin(s), end(s), ostream_iterator<string>(cout,"\n"));
}
