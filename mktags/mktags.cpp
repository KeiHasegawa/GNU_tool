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
#include <iomanip>
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

#include "bfd.h"
#include "dwarf2.h"

inline void usage(const char* prog)
{
  using namespace std;
  cerr << "usage % " << prog << " [-aenv][-E dir] a.out" << endl;
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

struct cont_t {
  std::string name;
  enum dwarf_tag kind;
  int file;
  int line;
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
  inline bool is_enum(const cont_t& c)
  {
    return c.kind == DW_TAG_enumeration_type;
  }
  inline bool is_enumerator(const cont_t& x)
  {
    return x.kind == DW_TAG_enumerator;
  }
  inline void modify_enumerator(cont_t& x, const cont_t& y)
  {
    assert(!x.file);
    x.file = y.file;
    assert(!x.line);
    x.line = y.line;
  }
  inline void modify_enumerator(info_t& x)
  {
    auto& contents = x.contents; 
    for (auto p = begin(contents) ; p != end(contents) ; ) {
      p = find_if(p, end(contents), is_enum);
      if (p != end(contents)) {
	const auto& enum_type = *p;
	auto b = p + 1;
	assert(b != end(contents));
	auto e = find_if(b, end(contents), not1(ptr_fun(is_enumerator)));
	assert(b < e);
	for ( ; b != e ; ++b)
	  modify_enumerator(*b, enum_type);
	p = e;
      }
    }
  }
  inline void modify_enumerator()
  {
    // Add line and file information to enumerator
    for (auto& x : info)
      modify_enumerator(x);
  }
  inline bool local(const cont_t& c)
  {
    return c.kind == DW_TAG_variable && !c.ext;
  }
  inline void erase_local(info_t& x)
  {
    auto& contents = x.contents; 
    auto p = remove_if(begin(contents), end(contents), local);
    contents.erase(p, end(contents));
  }
  inline void erase_local()
  {
    for (auto& x : info)
      erase_local(x);
  }
  inline void modify()
  {
    erase_local();
    modify_enumerator();
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
  assert(curr_dt == DW_TAG_compile_unit);
  assert(!info.empty());
  auto& b = info.back();
  assert(b.comp_dir.empty());
  b.comp_dir = ss;
}

std::string enum_name()
{
  using namespace std;
  static int cnt;
  ostringstream os;
  os << ".enum" << cnt++;
  return os.str();
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
  case DW_TAG_enumeration_type:
    {
      assert(!info.empty());
      auto& i = info.back();
      auto& contents = i.contents;
      if (contents.empty())
	return;
      auto& c = contents.back();
      if (c.kind != curr_dt) {
	if (curr_dt != DW_TAG_enumeration_type)
	  return;
	cont_t tmp = { enum_name(), DW_TAG_enumeration_type, (int)uvalue };
	contents.push_back(tmp);
	return;
      }
      if (c.kind == DW_TAG_enumerator)
	return;
      if (c.file)
	return;
      c.file = uvalue;
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
  case DW_TAG_union_type:
  case DW_TAG_member:
  case DW_TAG_namespace:
  case DW_TAG_class_type:
  case DW_TAG_enumeration_type:
    {
      assert(!info.empty());
      auto& i = info.back();
      auto& contents = i.contents;
      if (contents.empty())
	return;
      auto& c = contents.back();
      if (c.kind == DW_TAG_enumerator)
	return;
      if (c.line)
	return;
      if (!uvalue)
	return contents.pop_back();
      c.line = uvalue;
      return;
    }
  default:
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
  auto kind = c.kind;
  assert(kind == DW_TAG_variable);
  assert(!c.ext);
  c.ext = true;
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
    cont_t tmp = { name, (enum dwarf_tag)0, fileno, (int)lineno };
    info[current_off].push_back(tmp);
    return;
  }

  auto p = import.find(sec_offset);
  assert(p != end(import));
  auto fileno = p->second;
  cont_t tmp = { name, (enum dwarf_tag)0, fileno, (int)lineno };
  info[current_off].push_back(tmp);
}

namespace table {
  using namespace std;
  map<string, string> cache;
  string get_rpath(string dir)
  {
    assert(dir[0] == '/');
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
  inline string not_redundant(string path)
  {
    for (auto p = 0 ; p != string::npos ;) {
      auto debug = path.substr(p);
      p = path.find('.', p);
      if (p == string::npos)
	return path;
      switch (path[p+1]) {
      case '.':
	{
	  assert(path[p+2] == '/');
	  assert(path[p-1] == '/');
	  auto q = path.find_last_of('/', p-2);
	  assert(q != string::npos);
	  path.erase(q, p - q + 2);
	  p = q;
	  break;
	}
      case '/':
	path.erase(p, 2);
	break;
      default:
	++p;
	break;
      }
    }
    return path;
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
    if (dir == ".") {
      auto path = comp_dir + '/' + file;
      if (abs_path_form)
	res[path].push_back(&c);
      else {
	auto rpath = get_rpath(comp_dir);
	if (rpath.empty())
	  res[file].push_back(&c);
	else {
	  rpath = rpath + '/' + file;
	  res[rpath].push_back(&c);
	}
	extra[&c] = path;
      }
      return;
    }
    if (dir[0] == '/') {
      string rpath = get_rpath(dir);
      if (rpath.empty()) {
	res[file].push_back(&c);
	auto path = dir + '/' + file;
	extra[&c] = path;
	return;
      }
    }
    if (dir[0] == '.')
      dir = comp_dir + '/' + dir;
    auto path = dir + '/' + file;
    path = not_redundant(path);
    res[path].push_back(&c);
  }
  inline void create_if(const pair<string, int>& x,
			string comp_dir,
			const debug_line_impl::info_t& li,
			bool abs_path_form,
			const set<string>& exclude,
			result_t& res,
			map<const cont_t*, string>& extra)
  {
    auto p = find_if(begin(exclude), end(exclude),
		     bind2nd(ptr_fun(match), comp_dir));
    if (p != end(exclude))
      return;
    auto file = x.first;
    if (file[0] == '<' && file.back() == '>')
      return;  // skip if builtin
    int m = x.second;
    if (!m) {
      string apath = comp_dir + '/' + file;
      if (abs_path_form) {
	auto p = res.find(apath);
	if (p != end(res))
	  return;
	cont_t* tmp = new cont_t{ "", (enum dwarf_tag)0, 0, 1 };
	res[apath].push_back(tmp);
	return;
      }
      string rpath = get_rpath(comp_dir);
      if (!rpath.empty())
	rpath += '/' + file;
      else
	rpath = file;
      auto p = res.find(rpath);
      if (p != end(res))
	return;
      cont_t* tmp = new cont_t{ file, (enum dwarf_tag)0, 0, 1 };
      res[rpath].push_back(tmp);
      extra[tmp] = apath;
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
    if (dir == ".")
      return;
    if (dir[0] == '/') {
      auto rpath = get_rpath(dir);
      if (rpath.empty()) {
	auto p = res.find(file);
	if (p != end(res))
	  return;
      }
    }
    if (dir[0] == '.')
      dir = comp_dir + '/' + dir;
    auto path = dir + '/' + file;
    path = not_redundant(path);
    auto r = res.find(path);
    if (r != end(res))
      return;
    cont_t* tmp = new cont_t{ file, (enum dwarf_tag)0, 0, 1 };
    res[path].push_back(tmp);
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
  inline void create_if(const debug_info_impl::info_t& x,
			const pair<int, debug_line_impl::info_t>& y,
			bool abs_path_form, const set<string>& exclude,
			result_t& res, map<const cont_t*, string>& extra)
  {
    auto comp_dir = x.comp_dir;
    const auto& contents = x.contents;
    const auto& li = y.second;
    const auto& files = li.files;
    for (const auto& x : files)
      create_if(x, comp_dir, li, abs_path_form, exclude, res, extra);
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
  struct create_if_t {
    bool abs_path_form;
    const set<string>& exclude;
    result_t& res;
    map<const cont_t*, string>& extra;
    const map<int, vector<cont_t> >& z;
    create_if_t(bool a, const set<string>& s, result_t& r,
		map<const cont_t*, string>& m,
		const map<int, vector<cont_t> >& zz) : abs_path_form{a},
      exclude{s}, res{r}, extra{m}, z{zz} {}
    bool operator()(const debug_info_impl::info_t& x,
		    const pair<int, debug_line_impl::info_t>& y)
    {
      create_if(x, y, abs_path_form, exclude, res, extra);
      return true;
    }
  };
  inline void create(bool abs_path_form, const set<string>& exclude,
		     result_t& res, map<const cont_t*, string>& extra,
		     bool create_empty_file_entry)
  {
    const auto& x = debug_info_impl::info;
    const auto& y = debug_line_impl::info;
    const auto& z = debug_macro_impl::info;
    assert(x.size() == y.size());
    mismatch(begin(x), end(x), begin(y),
	     create_t(abs_path_form, exclude, res, extra, z));
    if (create_empty_file_entry)
      mismatch(begin(x), end(x), begin(y),
	       create_if_t(abs_path_form, exclude, res, extra, z));
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
		    vector<tag_t>& res, bool warn)
  {
    if (has_extra(file)) {
      auto p = extra.find(pcont);
      assert(p != end(extra));
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
	if (warn)
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
    static string last_text;
    if (text.empty())
      text = last_text;
    tag_t tmp = {
      text, pcont->name, pcont->line, seek, pcont->kind
    };
    res.push_back(tmp);
    last_text = text;
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
    return x->line == y->line;
  }
  using namespace table;
  inline void build(const pair<string, value_t>& p,
		    const map<const cont_t*, string>& extra,
		    map<string, vector<tag_t> >& res, bool warn)
  {
    value_t v = p.second;
    sort(begin(v), end(v), comp);
    value_t vv;
    unique_copy(begin(v), end(v), back_inserter(vv), comp2);
    string file = p.first;
    auto& dst = res[file];
    for (const auto& x : vv)
      build(file, x, extra, dst, warn);
  }

} // end of namespace goal

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
      default:
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
      auto c = fn[0];
      if (c != '.' && c != '/') {
	const auto& v = x.second;
	for (const auto& tag : v)
	  output(ofs, tag, fn);
      }
    }
    for (const auto& x : tags) {
      auto fn = x.first;
      auto c = fn[0];
      if (c == '.' || c == '/') {
	const auto& v = x.second;
	for (const auto& tag : v)
	  output(ofs, tag, fn);
      }
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

    for (const auto& x : raw) {
      auto file = x.first;
      auto c = file[0];
      if (c != '.' && c != '/')
	output1(ofs, x);
    }

    for (const auto& x : raw) {
      auto file = x.first;
      auto c = file[0];
      if (c == '.' || c == '/')
	output1(ofs, x);
    }
  }
} // end of namespace for_emacs

extern "C" void
display_file (char *filename, char *target, bfd_boolean last_file);

int main(int argc, char** argv)
{
  using namespace std;
  extern char* program_name;
  program_name = argv[0];
  bool abs_path_form = false;
  set<string> exclude;
  enum class mode_t { vi, emacs } mode = mode_t::vi;
  extern int verbose_flag;
  bool create_empty_file_entry = true;
  bool warn = true;
  for (int opt ; (opt = getopt(argc, argv, "aevE:wn")) != -1 ; ) {
    switch (opt) {
    case 'a': abs_path_form = true;            break;
    case 'e': mode = mode_t::emacs;            break;
    case 'v': verbose_flag = 1;                break;
    case 'E': exclude.insert(optarg);          break;
    case 'w': warn = false;                    break;
    case 'n': create_empty_file_entry = false; break;
    default:  usage(argv[0]); return 1;
    }
  }

  extern int dump_debugging;
  dump_debugging = 1;

  if (optind == argc)
    display_file (const_cast<char*>("a.out"), nullptr, TRUE);
  else {
    for ( ; optind < argc ; ++optind )
      display_file(argv[optind], nullptr, optind == argc - 1);
  }

  debug_info_impl::modify();

  table::result_t tbl;
  map<const cont_t*, string> extra;
  table::create(abs_path_form, exclude, tbl, extra,
		create_empty_file_entry);

  map<string, vector<goal::tag_t> > tags;
  for (const auto& x : tbl)
    goal::build(x, extra, tags, warn);

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

inline namespace {
using namespace std;
void debug(enum dwarf_tag dt)
{
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
  default:
    break;
  }
}
	 
void debug(const cont_t& x)
{
  cerr << '\t' << x.name << ',';
  debug(x.kind);
  cerr << ',' << x.file << ',' << x.line << ',' << x.ext << endl;
}

void debug(const debug_info_impl::info_t& x)
{
  cerr << x.compile_unit << ':' << x.comp_dir << endl;
  for (const auto& y : x.contents)
    debug(y);
}

void debug(const vector<pair<string, int> >& files)
{
  for (const auto& p : files)
    cerr << "\t\t" << p.first << ':' << dec << p.second << endl;
}

void debug(const vector<string>& dirs)
{
  cerr << "\t\t";
  copy(begin(dirs), end(dirs), ostream_iterator<string>(cerr, "\n\t\t"));
}

void debug(const debug_line_impl::info_t& x)
{
  auto dirs = x.dirs;
  cerr << '\t' << "Directory:" << endl;
  debug(dirs);
 
  cerr << '\b' << "Files:" << endl;
  debug(x.files);
}

void debug(const debug_line_impl::info_t* p)
{
  if (!p) {
    cerr << "(null)" << endl;
    return;
  }
  debug(*p);
}

void debug(const map<int, debug_line_impl::info_t>& m)
{
  for (const auto& x : m) {
    cerr << '\t' << "OFFSET :" << hex << "0x" << x.first << endl;
    debug(x.second);
  }
}

void debug1()
{
  cerr << "debug_line_impl" << endl;
  debug(debug_line_impl::info);
}

void debug(const vector<debug_info_impl::info_t>& v)
{
  for (const auto& x : v)
    debug(x);
}

void debug2()
{
  cerr << "debug_info" << endl;
  debug(debug_info_impl::info);
}

void debug(const map<int, vector<cont_t> >& m)
{
  for (const auto& x : m) {
    auto line_offset = x.first;
    cerr << "line offset : 0x" << hex << line_offset << endl;
    for (const auto& c : x.second)
      debug(c);
  }
}

void debug3()
{
  cerr << "debug_macro_impl" << endl;
  debug(debug_macro_impl::info);
}

void debug(const table::value_t& v)
{
  for (auto p : v)
    debug(*p);
}

void debug(const table::result_t& tbl)
{
  for (const auto& x : tbl) {
    cerr << x.first << endl;
    debug(x.second);
  }
}

void debug(const goal::tag_t& tag)
{
  cerr << tag.text << ':' << tag.name << ':';
  cerr << dec << tag.line << ':'<<  tag.seek << ':';
  debug(tag.kind);
  cerr << endl;
}

void debug(const vector<goal::tag_t>& v)
{
  for (const auto& t : v)
    debug(t);
}

void debug(const map<string, vector<goal::tag_t> >& tags)
{
  for (const auto& p : tags) {
    cerr << p.first << endl;
    debug(p.second);
  }
}

void debug(const map<const cont_t*, string>& extra)
{
  for (const auto& p : extra) {
    debug(*p.first);
    cerr << p.second << endl;
  }
}

void debug(const set<string>& s)
{
  copy(begin(s), end(s), ostream_iterator<string>(cerr, "\n"));
}

void debug(const vector<cont_t>& v)
{
  for (const auto& c : v)
    debug(c);
}

void debug(const bfd_byte* ptr, size_t sz)
{
  for (int i = 0 ; i != sz ; ++i) {
    if (i && !(i & 0xf))
      cerr << '\n';
    cerr << ' ' << setw(2) << setfill('0') << hex << int(ptr[i]);
  }
  cerr << endl;
}

} // end of inline namespace 
