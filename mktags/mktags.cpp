#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <cassert>

// Not refer to Dynamic Link Library at CYGWIN
extern "C" {
  int getopt(int, char**, const char*);
  extern char* optarg;
  extern int optind;
}

#include <bfd.h>
#include "dwarf2.h"

inline void usage(const char* prog)
{
  using namespace std;
  cerr << "usage % " << prog << " [-aev][-E dir] a.out" << endl;
}

extern "C" void my_display_debug_line(bfd*, bfd_section*, bfd_byte*);

inline void do_line(bfd* bp)
{
  using namespace std;
  const char* name = ".debug_line";
  auto section = bfd_get_section_by_name(bp, name);
  if (!section) {
    cerr << "Not foud : " << '"' << name << '"' << endl;
    return;
  }

  bfd_byte *buf;
  if (!bfd_malloc_and_get_section(bp, section, &buf)) {
    cerr << "bfd_malloc_and_get_section failed" << endl;
    return;
  }
  struct sweeper {
    bfd_byte* m_ptr;
    sweeper(bfd_byte* p) : m_ptr{p} {}
    ~sweeper(){ free(m_ptr); } 
  } sweeper(buf);

  my_display_debug_line(bp, section, buf);
}

namespace debug_line_impl {
  using namespace std;
  struct X {
    vector<string> dirs;
    vector<pair<string, int> > files;
  };
  map<int, X> info;
  int current_off;
  bool match(const X& x, string file, string dir)
  {
    int n = 0;
    if (!dir.empty()) {
      const auto& dirs = x.dirs;
      auto p = find(begin(dirs), end(dirs), dir);
      assert(p != end(dirs));
      n = distance(begin(dirs), p) + 1;
    }

    const auto& files = x.files;
    assert(!files.empty());
    auto p = find_if(begin(files), end(files),
	     [n](const pair<string, int>& x){ return x.second == n; });
    assert(p != end(files));
    return p->first == file;
  }
  X* get(string file, string dir)
  {
    auto p = find_if(begin(info), end(info),
   [file, dir](const pair<int, X>& p){ return match(p.second, file, dir); });
    assert(p != end(info));
    return &p->second;
  }
} // end of namespace debgu_line_impl 

extern "C" void dir_offset(long offset)
{
  debug_line_impl::current_off = offset;
}

extern "C" void dir_ent(unsigned char* s)
{
  using namespace debug_line_impl;
  auto ss = reinterpret_cast<char*>(s);
  info[current_off].dirs.push_back(ss);
}

extern "C" void file_entry(unsigned char* s, int dirno)
{
  using namespace debug_line_impl;
  auto ss = reinterpret_cast<char*>(s);  
  info[current_off].files.push_back(pair<string, int>(ss, dirno));
}

extern "C" void my_display_debug_info(bfd*, bfd_section*, bfd_byte*);

inline void do_info(bfd* bp)
{
  using namespace std;
  const char* name = ".debug_info";
  auto section = bfd_get_section_by_name(bp, name);
  if (!section) {
    cerr << "Not foud : " << '"' << name << '"' << endl;
    return;
  }

  bfd_byte *buf;
  if (!bfd_malloc_and_get_section(bp, section, &buf)) {
    cerr << "bfd_malloc_and_get_section failed" << endl;
    return;
  }
  struct sweeper {
    bfd_byte* m_ptr;
    sweeper(bfd_byte* p) : m_ptr{p} {}
    ~sweeper(){ free(m_ptr); } 
  } sweeper(buf);

  my_display_debug_info(bp, section, buf);
}

struct cont_t {
  std::string name;
  enum dwarf_tag kind;
  int line;
  int file;
};

namespace debug_info_impl {
  using namespace std;
  enum dwarf_tag curr_dt;
  struct info_t {
    string file;
    string dir;
    vector<cont_t>  contents;
    info_t(const char* s) : file{s} {}
  };
  vector<info_t> info;
  bool match(const info_t& x, string file)
  {
    return x.file == file;
  }
  info_t* get(string file)
  {
    auto p = find_if(begin(info), end(info),
		     [file](const info_t& x){ return match(x, file); });
    assert(p != end(info));
    return &*p;
  }
} // end of namespace debug_info_impl

extern "C" void  start_tag(enum dwarf_tag dt)
{
  debug_info_impl::curr_dt = dt;
}

extern "C" void set_name(unsigned const char* s)
{
  using namespace debug_info_impl;
  auto ss = reinterpret_cast<const char*>(s);
  switch (curr_dt) {
  case DW_TAG_base_type:
    return;
  case DW_TAG_compile_unit:
    info.push_back(info_t(ss));
    return;
  case DW_TAG_variable:
  case DW_TAG_subprogram:
  case DW_TAG_typedef:
  case DW_TAG_structure_type:
    {
      assert(!info.empty());
      auto& b = info.back();
      cont_t tmp = { ss, curr_dt };
      b.contents.push_back(tmp);
      return;
    }
  default:
    return;
  }
}

extern "C" void comp_dir(const unsigned char* s)
{
  using namespace debug_info_impl;
  auto ss = reinterpret_cast<const char*>(s);
  switch (curr_dt) {
  case DW_TAG_compile_unit:
    {
      assert(!info.empty());
      auto& b = info.back();
      assert(b.dir.empty());
      b.dir = ss;
      return;
    }
  default:
    return;
  }
}

extern "C" void set_decl_line(unsigned long long uvalue)
{
  using namespace debug_info_impl;
  switch (curr_dt) {
  case DW_TAG_variable:
  case DW_TAG_subprogram:
  case DW_TAG_typedef:
  case DW_TAG_structure_type:
    {
      assert(!info.empty());
      auto& i = info.back();
      auto& contents = i.contents;
      assert(!contents.empty());
      auto& c = contents.back();
      if (!c.line) {
	c.line = uvalue;
	return;
      }
      auto tmp = c;
      tmp.line = uvalue;
      contents.push_back(tmp);
      return;
    }
  default:
    return;
  }
}

extern "C" void set_decl_file(unsigned long long uvalue)
{
  using namespace debug_info_impl;
  switch (curr_dt) {
  case DW_TAG_variable:
  case DW_TAG_subprogram:
  case DW_TAG_typedef:
  case DW_TAG_structure_type:
    {
      assert(!info.empty());
      auto& i = info.back();
      auto& contents = i.contents;
      assert(!contents.empty());
      auto& c = contents.back();
      if (!c.file) {
	c.file = uvalue;
	return;
      }
      auto tmp = c;
      tmp.file = uvalue;
      tmp.line = 0;
      contents.push_back(tmp);
      return;
    }
  default:
    return;
  }
}

extern "C" void
my_display_debug_macro(bfd*, bfd_section*, bfd_byte*);

inline void do_macro(bfd* bp)
{
  using namespace std;
  auto section = bfd_get_section_by_name(bp, ".debug_macro");
  if (!section)
    return;
  bfd_byte *buf;
  if (!bfd_malloc_and_get_section(bp, section, &buf)) {
    cerr << "bfd_malloc_and_get_section failed" << endl;
    return;
  }
  struct sweeper {
    bfd_byte* m_ptr;
    sweeper(bfd_byte* p) : m_ptr{p} {}
    ~sweeper(){ free(m_ptr); } 
  } sweeper(buf);

  my_display_debug_macro(bp, section, buf);
}

namespace debug_macro_impl {
  using namespace std;
  vector<int> filenos;
  map<unsigned int, int> import;
  debug_line_impl::X* current;
  map<debug_line_impl::X*, vector<cont_t> > info;
} // end of namespace debug_macro_impl

extern "C"
void macro_start_file(unsigned int lineno, unsigned int fileno,
		      unsigned char* file, unsigned char* dir)
{
  using namespace std;
  if (!lineno) {
    auto ss = reinterpret_cast<char*>(file);
    auto tt = reinterpret_cast<char*>(dir);
    string tmp;
    if (tt)
      tmp = tt;
    debug_macro_impl::current = debug_line_impl::get(ss, tmp);
  }
  debug_macro_impl::filenos.push_back(fileno);
}

extern "C" void macro_end_file()
{
  using namespace debug_macro_impl;
  assert(!filenos.empty());
  filenos.pop_back();
}

extern "C" void macro_import(unsigned int offset)
{
  using namespace debug_macro_impl;
  if (filenos.empty())
    return;
  auto fileno = filenos.back();
  import[offset] = fileno;
}

extern "C"
void macro_define(unsigned int lineno, const unsigned char* s,
		  unsigned int sec_offset)
{
  using namespace std;
  if (!lineno)
    return;
  string name;
  for ( ; *s != '\0' ; ++s ) {
    char c = *s;
    if (c == ' ' || c == '\t' || c == '(')
      break;
    name += c;
  }

  using namespace debug_macro_impl;
 if (!filenos.empty()) {
   int fileno = filenos.back();
   cont_t tmp = { name, (enum dwarf_tag)0, (int)lineno, fileno };
   info[current].push_back(tmp);
   return;
 }

 auto p = import.find(sec_offset);
 assert(p != end(import));
 auto fileno = p->second;
 cont_t tmp = { name, (enum dwarf_tag)0, (int)lineno, fileno };
 info[current].push_back(tmp);
}

struct comp {
  bool operator()(const cont_t* x, const cont_t* y)
  {
    return x->line < y->line;
  }
};

typedef std::set<const cont_t*, comp> value_t;
typedef std::map<std::string, value_t> table_t;

inline bool match(std::string ex, std::string dir)
{
  return dir.substr(0, ex.length()) == ex;
}

inline void create(const cont_t& c, bool abs_path_form,
		   const std::set<std::string>& exclude,
		   debug_line_impl::X* ptr, table_t& res,
		   std::map<const cont_t*, std::string>& extra)
{
  using namespace std;
  int n = c.file;
  if (!n)
    return;
  --n;
  const auto& files = ptr->files;
  assert(n < files.size());
  auto xn = files[n];
  auto file = xn.first;
  int m = xn.second;
  if (!m) {
    auto p = find_if(begin(files), end(files),
		     [](const pair<string, int>& x){ return !x.second; });
    assert(p != end(files));
    auto ptr = debug_info_impl::get(p->first);
    auto dir = ptr->dir;
    auto q = find_if(begin(exclude), end(exclude),
		     bind2nd(ptr_fun(match), dir));
    if (q != end(exclude))
      return;
    auto path = dir + '/' + file;
    if (abs_path_form)
      res[path].insert(&c);
    else {
      res[file].insert(&c);
      extra[&c] = path;
    }
    return;
  }
  --m;
  const auto& dirs = ptr->dirs;
  assert(m < dirs.size());
  auto dir = dirs[m];
  auto p = find_if(begin(exclude), end(exclude),
		   bind2nd(ptr_fun(match), dir));
  if (p != end(exclude))
    return;
  auto path = dir + '/' + file;
  res[path].insert(&c);
}

inline void create(const debug_info_impl::info_t& x,  bool abs_path_form, 
		   const std::set<std::string>& exclude, table_t& res,
		   std::map<const cont_t*, std::string>& extra)
{
  using namespace std;
  auto file = x.file;
  string tmp;
  debug_line_impl::X* ptr = debug_line_impl::get(file, tmp);
  for (const auto& c : x.contents)
    create(c, abs_path_form, exclude, ptr, res, extra);
}

inline void create(bool abs_path_form,
		   const std::set<std::string>& exclude, table_t& res,
		   std::map<const cont_t*, std::string>& extra)
{
  for (const auto& x : debug_info_impl::info)
    create(x, abs_path_form, exclude, res, extra);

  for (const auto& x : debug_macro_impl::info) {
    auto ptr = x.first;
    for (const auto& c : x.second)
      create(c, abs_path_form, exclude, ptr, res, extra);
  }
}

struct tag_t {
  std::string text;
  std::string name;
  int line;
  int seek;
  enum dwarf_tag kind;
};

inline void build(std::string file, const cont_t* pcont,
		  const std::map<const cont_t*, std::string>& extra,
		  std::vector<tag_t>& res)
{
  using namespace std;
  if (file[0] != '/') {
    auto p = extra.find(pcont);
    assert(p != end(extra));
    file = p->second;
  }
  static string curr_file;
  static ifstream ifs;
  static int curr_line;
  if (curr_file != file) {
    if (!curr_file.empty())
      ifs.close();
    ifs.open(file.c_str());
    if (!ifs) {
      cerr << "cannot open " << file << endl;
      return;
    }
    curr_file = file;
    curr_line = 0;
  }

  string text;
  char buffer[256];
  int line = pcont->line - curr_line;
  while (line--) {
    do {
      ifs.clear();
      ifs.getline(&buffer[0], sizeof buffer);
      if (!line)
	text += buffer;
    } while (ifs.rdstate() == ios_base::failbit);
  }
  int seek = ifs.tellg();
  seek -= text.length()+1;
  auto len = text.length();
  if (text[len-1] == '\r')
    text.erase(len-1);
  tag_t tmp = {
    text, pcont->name, pcont->line, seek, pcont->kind
  };
  res.push_back(tmp);
  curr_line = pcont->line;
}

inline void build(const std::pair<std::string, value_t>& p,
		  const std::map<const cont_t*, std::string>& extra,
		  std::map<std::string, std::vector<tag_t> >& res)
{
  using namespace std;
  for (const auto& x : p.second) {
    string file = p.first;
    build(file, x, extra, res[file]);
  }
}

extern int verbose_flag;

namespace for_vi {
  using namespace std;
  inline void
  output(ostream& os, const tag_t& tag, string fn)
  {
    os << tag.name << '\t' << fn << '\t';
    auto kind = tag.kind;
    if (!kind)
      os << tag.line << ';' << '"' << '\t' << 'd' << '\t' << "file:";
    else {
      os << "/^" << tag.text << "$/;" << '"' << '\t';
      switch (kind) {
      case DW_TAG_variable: os << 'v'; break;
      case DW_TAG_subprogram: os << 'f'; break;
      case DW_TAG_typedef: os << 't'; break;
      case DW_TAG_structure_type: os << 's'; break;
      }
    }
    os << endl;
  }
  inline void
  output(const map<string, vector<tag_t> >& tags)
  {
    const char* tag_f = "tags";
    ofstream ofs(tag_f);
    if (!ofs) {
      cerr << "cannot open " << '"' << tag_f << '"' << '\n';
      return;
    }
    for (const auto& x : tags) {
      auto fn = x.first;
      const auto& v = x.second;
      for (const auto& tag : v)
	output(ofs, tag, fn);
    }
  }
} // end of namespace for_vi

namespace for_emacs {
  using namespace std;
  std::ostream& operator<<(std::ostream& os, const tag_t& x)
  {
    os << x.text << char(0177) << x.name << char(1);
    return os << x.line << ',' << x.seek;
  }
  inline string conv(const vector<tag_t>& v)
  {
    ostringstream ost;
    for (const auto& tag : v)
      ost << tag << '\n';
    return ost.str();
  }
  inline void
  output1(ostream& os, const pair<string, string>& x)
  {
    string fn = x.first;
    string contents = x.second;
    int len = contents.length();
    os << '\f' << '\n' << fn << ',' << len << '\n' << contents;
  }
  inline void
  output(const map<string, vector<tag_t> >& tags)
  {
    map<string, string> raw;
    for (const auto& x : tags)
      raw[x.first] = conv(x.second);

    const char* tag_f = "TAGS";
    ofstream ofs(tag_f);
    if (!ofs) {
      cerr << "cannot open " << '"' << tag_f << '"' << endl;
      return;
    }

    for (const auto& x : raw)
      output1(ofs, x);
  }
} // end of namespace for_emacs

int main(int argc, char** argv)
{
  using namespace std;
  bool abs_path_form = false;
  set<string> exclude;
  enum class mode_t { vi, emacs } mode = mode_t::vi;
  for (int opt ; (opt = getopt(argc, argv, "aevE:")) != -1 ; ) {
    switch (opt) {
    case 'a':
      abs_path_form = true;
      break;
    case 'e':
      mode = mode_t::emacs;
      break;
    case 'v':
      verbose_flag = 1;
      break;
    case 'E':
      exclude.insert(optarg);
      break;
    default:
      usage(argv[0]);
      return 1;
    }
  }
  if (argc - optind != 1) {
    usage(argv[0]);
    return 1;
  }

  bfd* bp = bfd_openr(argv[optind], 0);
  if (!bp) {
    cerr << "bfd_openr(" << argv[optind] << ") faled" << endl;
    return 1;
  }

  struct sweeper {
    bfd* m_bp;
    sweeper(bfd* bp) : m_bp{bp} {}
    ~sweeper(){ bfd_close(m_bp); }
  } sweeper(bp); 

  if (!bfd_check_format(bp, bfd_object)) {
    cerr << "bfd_check_format falied" << endl;
    return 1;
  }

  do_line(bp);

  do_info(bp);

  do_macro(bp);

  table_t tbl;
  map<const cont_t*, string> extra;
  create(abs_path_form, exclude, tbl, extra);

  map<string, vector<tag_t> > tags;
  for (const auto& x : tbl)
    build(x, extra, tags);

  switch (mode) {
  case mode_t::vi:
    for_vi::output(tags);
    break;
  case mode_t::emacs:
    for_emacs::output(tags);
    break;
  }

  return 0;
}

void debug(enum dwarf_tag dt)
{
  using namespace std;
  switch (dt) {
  case DW_TAG_variable: cerr << 'v'; break;
  case DW_TAG_subprogram: cerr << 'f'; break;
  case DW_TAG_typedef: cerr << 't'; break;
  case DW_TAG_structure_type: cerr << 's'; break;
  default: cerr << 'd'; break;
  }
}

void debug(const cont_t& x)
{
  using namespace std;
  cerr << '\t' << x.name << ',';
  debug(x.kind);
  cerr << ',' << x.line << ',' << x.file << endl;
}

void debug(const debug_info_impl::info_t& x)
{
  using namespace std;
  cerr << x.file << ':' << x.dir << endl;
  for (const auto& y : x.contents)
    debug(y);
}

void debug(const debug_line_impl::X& x)
{
  using namespace std;
  auto dirs = x.dirs;
  cerr << '\t' << "Directory:" << endl;
  cerr << "\t\t";
  copy(begin(dirs), end(dirs), ostream_iterator<string>(cerr, "\n\t\t"));
  
  cerr << '\b' << "Files:" << endl;
  for (const auto& p : x.files)
    cerr << "\t\t" << p.first << ':' << dec << p.second << endl;
}

void debug1()
{
  using namespace std;
  using namespace debug_line_impl;
  cerr << "DEBUG LINE" << endl;
  for (const auto& x : info) {
    cerr << '\t' << "OFFSET :" << hex << x.first << endl;
    debug(x.second);
  }
}

void debug2()
{
  using namespace debug_info_impl;
  cerr << "DEBUG INFO" << endl;
  for (const auto& x : info)
    debug(x);
}

void debug3()
{
  using namespace debug_macro_impl;
  cerr << "DEBUG MACRO" << endl;
  for (const auto& x : info) {
    const auto ptr = x.first;
    const auto& files = ptr->files;
    assert(!files.empty());
    auto p = find_if(begin(files), end(files),
		     [](const pair<string, int>& x){ return !x.second; });
    assert(p != end(files));
    cerr << "Include from : " << p->first <<endl;
    for (const auto& c : x.second)
      debug(c);
  }
}

void debug(const table_t& tbl)
{
  using namespace std;
  for (const auto& x : tbl) {
    cerr << x.first << endl;
    for (const auto& p : x.second)
      debug(*p);
  }
}

void debug(const tag_t& tag)
{
  using namespace std;
  cerr << tag.text << ':' << tag.name << ':';
  cerr << dec << tag.line << ':'<<  tag.seek << ':';
  debug(tag.kind);
  cerr << endl;
}

void debug(const std::map<std::string, std::vector<tag_t> >& tags)
{
  using namespace std;
  for (const auto& p : tags) {
    cerr << p.first << endl;
    for (const auto& t : p.second)
      debug(t);
  }
}
