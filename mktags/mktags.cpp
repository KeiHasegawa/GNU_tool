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
#ifdef __CYGWIN__
// Not refer to Dynamic Link Library at CYGWIN
extern "C" {
  int getopt(int, char**, const char*);
  extern char* optarg;
  extern int optind;

  extern char* getcwd(char*, size_t);
}
#else // __CYGWIN__
#include <unistd.h>
#endif // __CYGWIN__

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
  bool match(const X& x, string file, string dir, int* res)
  {
    int n = 0;
    if (!dir.empty()) {
      const auto& dirs = x.dirs;
      auto p = find(begin(dirs), end(dirs), dir);
      if (p != end(dirs))
	n = distance(begin(dirs), p) + 1;
      else {
#ifdef __CYGWIN__
	if (dir != ".")
	  asm("int3");
#else
	assert(dir == ".");
#endif
	n = 1;
      }
    }

    const auto& files = x.files;
    assert(!files.empty());
    auto p = find(begin(files), end(files),make_pair(file, n));
    if (p == end(files))
      return false;
    *res = distance(begin(files), p);
    return true;
  }
  pair<X*, int> get(string file, string dir)
  {
    if (dir == "../../.././winsup/cygwin/cygwin0.c")
      asm("int3");
    auto pos = file.find_last_of('/');
    if (pos != string::npos) {
      assert(dir.empty());
      dir = file.substr(0, pos);
      file.erase(0,pos+1);
    }

    int n;
    auto p = find_if(begin(info), end(info),
		     [file, dir, &n](const pair<int, X>& p)
		     { return match(p.second, file, dir, &n); });
    assert(p != end(info));
    return make_pair(&p->second,n);
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

extern "C" enum dwarf_tag curr_tag()
{
  return debug_info_impl::curr_dt;
}

bool trace_break;

extern "C" void set_name(unsigned const char* s)
{
  using namespace debug_info_impl;
  auto ss = reinterpret_cast<const char*>(s);
  switch (curr_dt) {
  case DW_TAG_base_type:
  case DW_TAG_unspecified_type:
  case DW_TAG_formal_parameter:
  case DW_TAG_template_value_param:
  case DW_TAG_GNU_template_parameter_pack:
    return;
  case DW_TAG_compile_unit:
    info.push_back(info_t(ss));
    return;
  case DW_TAG_variable:
  case DW_TAG_subprogram:
  case DW_TAG_typedef:
  case DW_TAG_structure_type:
  case DW_TAG_union_type:
  case DW_TAG_member:
  case DW_TAG_namespace:
  case DW_TAG_class_type:
  case DW_TAG_enumerator:
  case DW_TAG_enumeration_type:
  case DW_TAG_template_type_param:
  case DW_TAG_pointer_type:
    {
      assert(!info.empty());
      auto& b = info.back();
      cont_t tmp = { ss, curr_dt };
      b.contents.push_back(tmp);
      return;
    }
  default:
    if (trace_break)
      asm("int3");
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
    if (trace_break)
      asm("int3");
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
  case DW_TAG_union_type:
  case DW_TAG_member:
  case DW_TAG_namespace:
  case DW_TAG_class_type:
  case DW_TAG_enumerator:
  case DW_TAG_enumeration_type:
  case DW_TAG_template_type_param:
  case DW_TAG_pointer_type:
    {
      assert(!info.empty());
      auto& i = info.back();
      auto& contents = i.contents;
      if (contents.empty())
	return;
      auto& c = contents.back();
      if (!c.line) {
	c.line = uvalue;
	if (!uvalue)
	  contents.pop_back();
	return;
      }
      auto tmp = c;
      tmp.line = uvalue;
      contents.push_back(tmp);
      return;
    }
  default:
    if (trace_break)
      asm("int3");
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
  case DW_TAG_union_type:
  case DW_TAG_member:
  case DW_TAG_namespace:
  case DW_TAG_class_type:
  case DW_TAG_enumerator:
  case DW_TAG_enumeration_type:
  case DW_TAG_template_type_param:
  case DW_TAG_pointer_type:
    {
      assert(!info.empty());
      auto& i = info.back();
      auto& contents = i.contents;
      if (contents.empty())
	return;
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
    if (trace_break)
      asm("int3");
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
  typedef pair<debug_line_impl::X*, int> KEY;
  KEY current;
  map<KEY, vector<cont_t> > info;
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

inline bool match(std::string ex, std::string dir)
{
  return dir.substr(0, ex.length()) == ex;
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
    auto& debug = info[current].back();
    cont_t* p = &debug;
    return;
  }

  auto p = import.find(sec_offset);
  assert(p != end(import));
  auto fileno = p->second;
  cont_t tmp = { name, (enum dwarf_tag)0, (int)lineno, fileno };
  info[current].push_back(tmp);
}

namespace table {
  using namespace std;
  string get_rpath(string dir)
  {
    char cwd[256];
    getcwd(&cwd[0], sizeof cwd);
    if (dir == cwd)
      return "";
    string x = dir;
    string y = cwd;
    string ret;
    while (1) {
      auto p = x.find_last_of('/');
      auto tail = x.substr(p);
      x = x.substr(0, p);
      auto q = y.find_last_of('/');
      y = y.substr(0, q);
      ret += ".." + tail + '/';
      if (x == y)
	break;
    }
    return ret;
  }
  typedef vector<const cont_t*> value_t;
  typedef map<string, value_t> result_t;
  inline void create(const cont_t& c, bool abs_path_form,
		     const set<string>& exclude,
		     const pair<debug_line_impl::X*, int>& key,
		     result_t& res,
		     map<const cont_t*, string>& extra)
  {
    int n = c.file;
    if (!n) {
      if (trace_break)
	asm("int3");
      return;
    }
    auto ptr = key.first;
    int base = key.second;
    int pos = base + n - 1;
    const auto& files = ptr->files;
    assert(pos < files.size());
    const auto bf = files[base].first;
    const auto& x = files[pos];
    auto file = x.first;
    int m = x.second;
    if (!m) {
      auto ptr = debug_info_impl::get(bf);
      auto dir = ptr->dir;
      string apath = dir + '/' + file;
      if (abs_path_form)
	res[apath].push_back(&c);
      else {
	string rpath = get_rpath(dir);
	rpath += file;
	res[rpath].push_back(&c);
	extra[&c] = apath;
      }
      return;
    }
    if (trace_break)
      asm("int3");
    --m;
    const auto& dirs = ptr->dirs;
    assert(m < dirs.size());
    auto dir = dirs[m];
    auto p = find_if(begin(exclude), end(exclude),
		     bind2nd(ptr_fun(match), dir));
    if (p != end(exclude))
      return;
    auto path = dir + '/' + file;
    res[path].push_back(&c);
  }
  inline void create(const cont_t& c, bool abs_path_form,
		     const set<string>& exclude,
		     string file, string dir,
		     result_t& res,
		     map<const cont_t*, string>& extra)
  {
    int n = c.file;
    if (n != 1) {
      auto key = debug_line_impl::get(file, "");
      return create(c, abs_path_form, exclude, key, res, extra);
    }

    string path = dir + '/' + file;
    if (abs_path_form) {
      res[path].push_back(&c);
      return;
    }
    string rpath = get_rpath(dir);
    rpath += file;
    res[rpath].push_back(&c);
    extra[&c] = path;
  }
  inline void create(const debug_info_impl::info_t& x,  bool abs_path_form, 
		     const set<string>& exclude, result_t& res,
		     map<const cont_t*, string>& extra)
  {
    auto file = x.file;
    auto dir = x.dir;
    for (const auto& c : x.contents)
      create(c, abs_path_form, exclude, file, dir, res, extra);
  }
  inline void
  create(const debug_macro_impl::KEY& key, const vector<cont_t>& contents,
	 bool abs_path_form, const set<string>& exclude,
	 result_t& res, map<const cont_t*, string>& extra)
  {
    for (const auto& c : contents)
      create(c, abs_path_form, exclude, key, res, extra);
  }
  inline void create(bool abs_path_form, const set<string>& exclude,
		     result_t& res, map<const cont_t*, string>& extra)
  {
    for (const auto& x : debug_info_impl::info)
      create(x, abs_path_form, exclude, res, extra);

    for (const auto& x : debug_macro_impl::info)
      create(x.first, x.second, abs_path_form, exclude, res, extra);
  }
} // end fo namespace table

namespace goal {
  using namespace std;
  struct tag_t {
    string text;
    string name;
    int line;
    int seek;
    enum dwarf_tag kind;
  };
  inline void build(string file, const cont_t* pcont,
		    const map<const cont_t*, string>& extra,
		    vector<tag_t>& res)
  {
    char c = file[0];
    if (c != '/' && c != '.') {
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
    assert(line >= 0);
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
  inline bool comp(const cont_t* x, const cont_t* y)
  {
    return x->line < y->line;
  }
  using namespace table;
  inline void build(const pair<string, value_t>& p,
		    const map<const cont_t*, string>& extra,
		    map<string, vector<tag_t> >& res)
  {
    value_t v = p.second;
    sort(begin(v), end(v), comp);
    for (const auto& x : v) {
      string file = p.first;
      build(file, x, extra, res[file]);
    }
  }

} // end of namespace goal

extern int verbose_flag;

namespace for_vi {
  using namespace std;
  using namespace goal;
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
      case DW_TAG_variable:
	os << 'v'; break;
      case DW_TAG_subprogram:
	os << 'f'; break;
      case DW_TAG_typedef:
	os << 't'; break;
      case DW_TAG_structure_type:
	os << 's'; break;
      case DW_TAG_union_type:
	os << 'u'; break;
      case DW_TAG_member:
	os << 'm'; break;
      case DW_TAG_namespace:
	os << 'N'; break;
      case DW_TAG_class_type:
	os << 'c'; break; 
      case DW_TAG_enumerator:
	os << 'e'; break;
      case DW_TAG_enumeration_type:
	os << 'E'; break;
      case DW_TAG_template_type_param:
	os << 'T'; break;
      case DW_TAG_pointer_type:
	os << 'P'; break;
      default:
	if (trace_break)
	  asm("int3");
	break;
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
  using namespace goal;
  ostream& operator<<(ostream& os, const tag_t& x)
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
  for (int opt ; (opt = getopt(argc, argv, "aevE:t")) != -1 ; ) {
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
    case 't':
      trace_break = true;
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

  table::result_t tbl;
  map<const cont_t*, string> extra;
  table::create(abs_path_form, exclude, tbl, extra);

  map<string, vector<goal::tag_t> > tags;
  for (const auto& x : tbl)
    goal::build(x, extra, tags);

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
  case DW_TAG_padding: cerr << 'd'; break;
  case DW_TAG_variable: cerr << 'v'; break;
  case DW_TAG_subprogram: cerr << 'f'; break;
  case DW_TAG_typedef: cerr << 't'; break;
  case DW_TAG_structure_type: cerr << 's'; break;
  case DW_TAG_union_type: cerr << 'u'; break;
  case DW_TAG_member: cerr << 'm'; break;
  case DW_TAG_namespace: cerr << 'N'; break;
  case DW_TAG_class_type: cerr << 'c'; break; 
  case DW_TAG_enumerator: cerr << 'e'; break;
  case DW_TAG_enumeration_type: cerr << 'E'; break;
  case DW_TAG_template_type_param: cerr << 'T'; break;
  case DW_TAG_pointer_type: cerr << 'P'; break;
  default:
    if (trace_break)
      asm("int3");
    break;
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

void debug(const std::vector<std::pair<std::string, int> >& files)
{
  using namespace std;
  for (const auto& p : files)
    cerr << "\t\t" << p.first << ':' << dec << p.second << endl;
}

void debug(const std::vector<std::string>& dirs)
{
  using namespace std;
  cerr << "\t\t";
  copy(begin(dirs), end(dirs), ostream_iterator<string>(cerr, "\n\t\t"));
}

void debug(const debug_line_impl::X& x)
{
  using namespace std;
  auto dirs = x.dirs;
  cerr << '\t' << "Directory:" << endl;
  debug(dirs);
 
  cerr << '\b' << "Files:" << endl;
  debug(x.files);
}

void debug(const debug_line_impl::X* x)
{
  using namespace std;
  if (!x) {
    cerr << "(null)" << endl;
    return;
  }
  debug(*x);
}

void debug1()
{
  using namespace std;
  using namespace debug_line_impl;
  cerr << "debug_line_impl" << endl;
  for (const auto& x : info) {
    cerr << '\t' << "OFFSET :" << hex << x.first << endl;
    debug(x.second);
  }
}

void debug2()
{
  using namespace debug_info_impl;
  cerr << "debug_info" << endl;
  for (const auto& x : info)
    debug(x);
}

void debug3()
{
  using namespace debug_macro_impl;
  cerr << "debug_macro_impl" << endl;
  for (const auto& x : info) {
    auto key = x.first;
    cerr << "Groupe : pair<debug_line_impl::X*, int> ";
    cerr << key.first << ',' << key.second << endl;
    for (const auto& c : x.second)
      debug(c);
  }
}

void debug(const table::result_t& tbl)
{
  using namespace std;
  for (const auto& x : tbl) {
    cerr << x.first << endl;
    for (const auto& p : x.second)
      debug(*p);
  }
  cerr << flush;
}

void debug(const goal::tag_t& tag)
{
  using namespace std;
  cerr << tag.text << ':' << tag.name << ':';
  cerr << dec << tag.line << ':'<<  tag.seek << ':';
  debug(tag.kind);
  cerr << endl;
}

void debug(const std::map<std::string, std::vector<goal::tag_t> >& tags)
{
  using namespace std;
  for (const auto& p : tags) {
    cerr << p.first << endl;
    for (const auto& t : p.second)
      debug(t);
  }
}

void debug(const std::map<const cont_t*, std::string>& extra)
{
  using namespace std;
  for (const auto& p : extra) {
    debug(*p.first);
    cerr << p.second << endl;
  }
}

void debug(const std::set<std::string>& s)
{
  using namespace std;
  copy(begin(s), end(s), ostream_iterator<string>(cerr, "\n"));
}
