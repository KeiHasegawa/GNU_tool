#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <fstream>
#ifdef __CYGWIN__
// Not refer to DLL
extern "C" {
  int getopt(int, char**, const char*);
  extern char* optarg;
  extern int optind;
}
#else // __CYGWIN__
#include <unistd.h>
#endif // __CYGWIN__
#include <bfd.h>

inline void usage(const char* prog)
{
  using namespace std;
  cerr << "usage % " << prog << " [-e] a.out" << endl;
}

struct info_t {
  std::string name;
  const char* file;
  int line;
  flagword flags;
};

inline bool operator<(const info_t& x, const info_t& y)
{
  int n = strcmp(x.file, y.file);
  if (n)
    return n < 0;
  return x.line < y.line;
}

inline void
collect(bfd_symbol* sym, bfd_symbol** syms, std::vector<info_t>& res)
{
  using namespace std;
  auto flags = sym->flags;
  auto mask = BSF_FILE;
  if (flags & mask)
    return;
  const char* name = sym->name;
  if (name[0] == '.')
    return;
  auto bp = sym->the_bfd;
  const char* file;
  unsigned int line;
#ifdef __CYGWIN__
  auto sec = sym->section;
  auto off = sym->value;
  const char* func;
  if (!bfd_find_nearest_line(bp, sec, syms, off, &file, &func, &line))
    return;
  if (!line)
    return;
  --line;
#else // __CYGWIN__
  if (!bfd_find_line(bp, syms, sym, &file, &line))
    return;
  if (!file)
    return;
#endif // __CYGWIN__
  info_t tmp = { name, file, (int)line, flags };
  res.push_back(tmp);
}

struct tag_t {
  std::string text;
  std::string name;
  int line;
  int seek;
  flagword flags;
};

inline void
build(const info_t& x, std::map<std::string, std::vector<tag_t> >& res)
{
  using namespace std;
  static string curr_file;
  static ifstream ifs;
  static int curr_line;
  if (curr_file != x.file) {
    if (!curr_file.empty())
      ifs.close();
    ifs.open(x.file);
    if (!ifs) {
      cerr << "cannot open " << x.file << endl;
      return;
    }
    curr_file = x.file;
    curr_line = 0;
  }

  string text;
  char buffer[256];
  int line = x.line - curr_line;
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
  tag_t tmp = { text, x.name, x.line, seek, x.flags };
  res[curr_file].push_back(tmp);
  curr_line = x.line;
}

namespace for_vi {
  using namespace std;
  inline void
  output(ostream& os, const tag_t& tag, string fn)
  {
    os << tag.name << '\t' << fn << '\t';
    os << "/^" << tag.text << "$/;" << '"' << '\t';
    auto flags = tag.flags;
    if (flags & BSF_FUNCTION)
      os << 'f';
    else if (flags & BSF_OBJECT)
      os << 'v';
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
  enum class mode_t { vi, emacs } mode = mode_t::vi;
  for (int opt ; (opt = getopt(argc, argv, "e")) != -1 ; ) {
    switch (opt) {
    case 'e':
      mode = mode_t::emacs;
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

  int n = bfd_get_symtab_upper_bound(bp);
  if (n < 0) {
    cerr << "bfd_get_symtab_upper_bound falied" << endl;
    return 1;
  }

  auto syms = reinterpret_cast<bfd_symbol**>(new char[n]);
  unique_ptr<bfd_symbol*> sweeper2(syms);

  int nsym = bfd_canonicalize_symtab(bp, syms);
  if (!nsym) {
    cerr << "bfd_canonicalize_symtab failed" << endl;
    return 1;
  }

  vector<info_t> info;
  for (auto p = &syms[0] ; p != &syms[nsym] ; ++p)
    collect(*p, syms, info);

  if (info.empty()) {
    cerr << "No line information" << endl;
    return 1;
  }

  sort(begin(info), end(info));

  map<string, vector<tag_t> > tags;
  for (const auto& x : info)
    build(x, tags);

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

using namespace std;

void debug1(bfd_symbol* sym)
{
  cerr << sym->name << ':' << hex << sym->value << endl;
}

void debug(bfd_symbol** syms, int nsym)
{
  for_each(&syms[0], &syms[nsym], debug1);
}

void debug2(const info_t& info)
{
  cerr << info.name << ':' << info.file << ':' << dec << info.line;
  cerr << ':' << hex << info.flags << endl;
}

void debug(const vector<info_t>& info)
{
  for (const auto& x : info)
    debug2(x);
}

void debug3(const tag_t& tag)
{
  cerr << tag.text << ':' << tag.name << ':';
  cerr << dec << tag.line << ':'<<  tag.seek;
  cerr << hex << tag.flags << endl;
}

void debug(const map<string, vector<tag_t> >& tags)
{
  for (const auto& x : tags) {
    cerr << x.first << endl;
    const auto & v = x.second;
    for_each(begin(v), end(v), debug3);
  }
}
