#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <numeric>
#include <cassert>
#ifdef __CYGWIN__
// Not refer to getopt defined at Dynamic Link Library at CYGWIN
// For above, not include <unistd.h>
extern "C" {
  int getopt(int, char**, const char*);
  extern char* optarg;
  extern int optind;
  extern char* get_current_dir_name();
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
  struct info_t {
    vector<string> dirs;
    vector<pair<string, int> > files;
  };
  map<int, info_t> info;
  int current_off;
} // end of namespace debug_line_impl 

extern "C" void set_offset(long offset)
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
  bool ext;
};

namespace debug_info_impl {
  using namespace std;
  enum dwarf_tag curr_dt;
  struct info_t {
    string compile_unit;
    string comp_dir;
    vector<cont_t>  contents;
    info_t(const char* s) : compile_unit{s} {}
  };
  vector<info_t> info;
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
  assert(curr_dt == DW_TAG_compile_unit);
  assert(!info.empty());
  auto& b = info.back();
  assert(b.comp_dir.empty());
  b.comp_dir = ss;
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

extern "C" void set_ext()
{
  using namespace debug_info_impl;
  if (curr_dt != DW_TAG_variable)
    return;
  auto& i = info.back();
  auto& contents = i.contents;
  assert(!contents.empty());
  auto& c = contents.back();
  c.ext = true;
}

extern "C" void  set_loc(unsigned char*)
{
  using namespace debug_info_impl;
  if (curr_dt != DW_TAG_variable)
    return;
  auto& i = info.back();
  auto& contents = i.contents;
  assert(!contents.empty());
  auto& c = contents.back();
  if (c.ext)
    return;
  contents.pop_back();
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
  int current_off;
  map<int, vector<cont_t> > info;
} // end of namespace debug_macro_impl

extern "C"
void set_line_offset(unsigned long offset)
{
  debug_macro_impl::current_off = offset;
}

extern "C"
void macro_start_file(unsigned int lineno, unsigned int fileno,
		      unsigned char* file, unsigned char* dir)
{
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
    info[current_off].push_back(tmp);
    return;
  }

  auto p = import.find(sec_offset);
  assert(p != end(import));
  auto fileno = p->second;
  cont_t tmp = { name, (enum dwarf_tag)0, (int)lineno, fileno };
  info[current_off].push_back(tmp);
}

namespace table {
  using namespace std;
  map<string, string> cache;
  string get_rpath(string dir)
  {
    auto p = cache.find(dir);
    if (p != end(cache))
      return p->second;
    char* cwd = get_current_dir_name();
    if (!cwd) {
      cerr << "get_current_dir_name failed" << endl;
      return "";
    }
    struct sweeper {
      char* ptr;
      sweeper(char* p) : ptr{p} {}
      ~sweeper(){ free(ptr); }
    } sweeper(cwd);
    if (dir == cwd)
      return "";
    string x = dir;
    int n = count(begin(x), end(x), '/');
    string y = cwd;
    int m = count(begin(y), end(y), '/');
    string ret;

    if (n < m) {
      while (n != m) {
	auto p = y.find_last_of('/');
	y = y.substr(0,p);
	ret += "../";
	--m;
      }
    }
    vector<string> tails;
    if (n > m) {
      while (n != m) {
	auto p = x.find_last_of('/');
	auto tail = x.substr(p);
	tails.push_back(tail);
	x = x.substr(0, p);
	--n;
      }
    }
    int k = tails.size();
    while (1) {
      auto p = x.find_last_of('/');
      auto tail = x.substr(p);
      tails.push_back(tail);
      x = x.substr(0, p);
      auto q = y.find_last_of('/');
      y = y.substr(0, q);
      if (x == y)
	break;
    }
    ret += "..";
    assert(tails.size() > k);
    for (int i = k+1 ; i != tails.size() ; ++i)
      ret += "/..";
    ret = accumulate(rbegin(tails), rend(tails), ret);
    return cache[dir] = ret;
  }
  inline bool match(string ex, string dir)
  {
    return dir.substr(0, ex.length()) == ex;
  }
  typedef vector<const cont_t*> value_t;
  typedef map<string, value_t> result_t;
  inline void create(const cont_t& c, string comp_dir,
		     const debug_line_impl::info_t& li, bool abs_path_form,
		     const set<string>& exclude, result_t& res,
		     map<const cont_t*, string>& extra)
  {
    auto p = find_if(begin(exclude), end(exclude),
		     bind2nd(ptr_fun(match), comp_dir));
    if (p != end(exclude))
      return;
    int n = c.file;
    if (!n) {
      // For example, case of `__builtin_va_list', `__dso_handle',
      // `_GLOBAL__sub_I_main', `__static_initialization_and_destruction_0'
      // Just ignore
      return;
    }
    int pos = n - 1;
    const auto& files = li.files;
    assert(pos < files.size());
    const auto& y = files[pos];
    auto file = y.first;
    int m = y.second;
    if (!m) {
      string apath = comp_dir + '/' + file;
      if (abs_path_form)
	res[apath].push_back(&c);
      else {
	string rpath = get_rpath(comp_dir);
	if (!rpath.empty())
	  rpath += '/' + file;
	else
	  rpath = file;
	res[rpath].push_back(&c);
	extra[&c] = apath;
      }
      return;
    }
    --m;
    const auto& dirs = li.dirs;
    assert(m < dirs.size());
    auto dir = dirs[m];
    auto q = find_if(begin(exclude), end(exclude),
		     bind2nd(ptr_fun(match), dir));
    if (q != end(exclude))
      return;
    if (dir[0] == '.') {
      string rpath = get_rpath(comp_dir);
      if (!rpath.empty())
	dir = comp_dir + '/' + dir;
    }
    auto path = dir + '/' + file;
    res[path].push_back(&c);
  }
  inline void create(const debug_info_impl::info_t& x,
		     const pair<int, debug_line_impl::info_t>& y,
		     bool abs_path_form, const set<string>& exclude,
		     result_t& res, map<const cont_t*, string>& extra)
  {
    auto comp_dir = x.comp_dir;
    const auto& contents = x.contents;
    const auto& li = y.second;
    for (const auto& c : contents)
      create(c, comp_dir, li, abs_path_form, exclude, res, extra);
  }
  inline void
  create(const vector<cont_t>& contents, string comp_dir,
	 const debug_line_impl::info_t& li, bool abs_path_form,
	 const set<string>& exclude, result_t& res,
	 map<const cont_t*, string>& extra)
  {
    for (const auto& c : contents)
      create(c, comp_dir, li, abs_path_form, exclude, res, extra);
  }
  struct create_t {
    bool abs_path_form;
    const set<string>& exclude;
    result_t& res;
    map<const cont_t*, string>& extra;
    const map<int, vector<cont_t> >& z;
    create_t(bool a, const set<string>& s, result_t& r,
	     map<const cont_t*, string>& m,
	     const map<int, vector<cont_t> >& zz) : abs_path_form{a},
      exclude{s}, res{r}, extra{m}, z{zz} {}
    bool operator()(const debug_info_impl::info_t& x,
		    const pair<int, debug_line_impl::info_t>& y)
    {
      create(x, y, abs_path_form, exclude, res, extra);
      auto line_offset = y.first;
      auto p = z.find(line_offset);
      if (p != end(z)) {
	const auto& contents = p->second;
	const auto comp_dir = x.comp_dir;
	const auto& li = y.second;
	create(contents, comp_dir, li, abs_path_form, exclude, res, extra);
      }
      return true;
    }
  };
  inline void create(bool abs_path_form, const set<string>& exclude,
		     result_t& res, map<const cont_t*, string>& extra)
  {
    const auto& x = debug_info_impl::info;
    const auto& y = debug_line_impl::info;
    const auto& z = debug_macro_impl::info;
    assert(x.size() == y.size());
    mismatch(begin(x), end(x), begin(y),
	     create_t(abs_path_form, exclude, res, extra, z));
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
  inline bool has_extra(string file)
  {
    char c = file[0];
    if (c == '.')
      return false;
    if (c == '/')
      return false;
#ifdef __CYGWIN__
    if (file.length() < 3)
      return true;
    if (file[1] != ':')
      return true;
    return file[2] != '/';
#else // __CYGWIN__
    return true;
#endif // __CYGWIN__
  }
  inline void build(string file, const cont_t* pcont,
		    const map<const cont_t*, string>& extra,
		    vector<tag_t>& res)
  {
    if (has_extra(file)) {
      auto p = extra.find(pcont);
      if (p == end(extra)) {
	cerr << file << endl;
	abort();
      }
      file = p->second;
    }
    static set<string> cannot_open;
    if (cannot_open.find(file) != end(cannot_open))
      return;
    static string curr_file;
    static ifstream ifs;
    static int curr_line;
    if (curr_file != file) {
      if (!curr_file.empty())
	ifs.close();
      ifs.open(file);
      if (!ifs) {
	cerr << "cannot open " << file << endl;
	cannot_open.insert(file);
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
  inline bool comp2(const cont_t* x, const cont_t* y)
  {
    if (x->name != y->name)
      return false;
    if (x->line != y->line)
      return false;
    return x->file == y->file;
  }
  using namespace table;
  inline void build(const pair<string, value_t>& p,
		    const map<const cont_t*, string>& extra,
		    map<string, vector<tag_t> >& res)
  {
    value_t v = p.second;
    sort(begin(v), end(v), comp);
    value_t vv;
    unique_copy(begin(v), end(v), back_inserter(vv), comp2);
    for (const auto& x : vv) {
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
    for (const auto& x : tags) {
      const auto& v = x.second;
      if (!v.empty())
	raw[x.first] = conv(v);
    }

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
  cerr << x.compile_unit << ':' << x.comp_dir << endl;
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

void debug(const debug_line_impl::info_t& x)
{
  using namespace std;
  auto dirs = x.dirs;
  cerr << '\t' << "Directory:" << endl;
  debug(dirs);
 
  cerr << '\b' << "Files:" << endl;
  debug(x.files);
}

void debug(const debug_line_impl::info_t* p)
{
  using namespace std;
  if (!p) {
    cerr << "(null)" << endl;
    return;
  }
  debug(*p);
}

void debug1()
{
  using namespace std;
  using namespace debug_line_impl;
  cerr << "debug_line_impl" << endl;
  for (const auto& x : info) {
    cerr << '\t' << "OFFSET :" << hex << "0x" << x.first << endl;
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
    auto line_offset = x.first;
    cerr << "line offset : 0x" << hex << line_offset << endl;
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

void debug(const std::vector<cont_t>& v)
{
  for (const auto& c : v)
    debug(c);
}
