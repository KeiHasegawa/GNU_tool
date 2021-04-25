#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <bfd.h>

#ifdef __x86_64__
typedef uint64_t addr_type;
#else // __x86_64__
typedef uint32_t addr_type;
#endif // __x86_64__

int read_bb(const char* bbout, std::vector<addr_type>& res)
{
  using namespace std;
  ifstream ifs(bbout);
  if (!ifs) {
    cerr << "cannot open " << bbout << endl;
    return -1;
  }
  while (1) {
    union {
      addr_type addr;
      char c[sizeof addr];
    };
    ifs.read(&c[0], sizeof c);
    if (ifs.eof())
      return 0;
    res.push_back(addr);
  }
}

// extern const struct dwarf_debug_section dwarf_debug_sections[];

extern "C" int myfunc();

inline bool
find_caller_1(bfd* abfd, asection* sect, asymbol** syms, addr_type addr)
{
  auto flags = sect->flags;
  if (!(flags & SEC_ALLOC))
    return false;

  addr_type vma = sect->vma;
#ifdef __CYGWIN__
  addr &= 0x0000ffff;
  addr |= vma;
#endif // __CYGWIN__
  if (addr < vma)
    return false;

  size_t size = sect->size;
  if (addr >= vma + size)
    return false;

  const char* filename;
  const char* functionname;
  unsigned int line;
  unsigned int discriminator;
#if 1
  auto ret = myfunc(abfd, sect, syms, addr - vma,
					&filename, &functionname,
					&line, &discriminator);
#else
  auto ret = 
    bfd_find_nearest_line_discriminator(abfd, sect, syms, addr - vma,
					&filename, &functionname,
					&line, &discriminator);
#endif
  using namespace std;
  if (!ret) {
    cerr << hex << addr << " not found" << endl;
    return false;
  }

  cout << filename << ':' << functionname << ':' << line << endl;
  return true;
}

inline void find_caller(bfd* abfd, asymbol** syms, addr_type addr)
{
  for (asection* sect = abfd->sections ; sect ; sect = sect->next) {
    if (find_caller_1(abfd, sect, syms, addr))
      return;
  }
}

int main(int argc, char** argv)
{
  using namespace std;
  if (argc != 3) {
    cerr << "usage % " << argv[0] << " a.out bb.out" << endl;
    return 1;
  }

  vector<addr_type> addrs;
  if (read_bb(argv[2], addrs) < 0)
    return 2;

  bfd* abfd = bfd_openr(argv[1], 0);
  if (!abfd) {
    cerr << "bfd_openr failed : " << argv[1] << endl;
    return 3;
  }

  struct sweeper {
    bfd* m_bfd;
    sweeper(bfd* abfd) : m_bfd{abfd} {}
    ~sweeper()
    {
      bfd_close(m_bfd);
    }
  } sweeper(abfd);

  if (!bfd_check_format(abfd, bfd_object)) {
    cerr << "bfd_check_format failed" << endl;
    return 4;
  }

  int upper =  bfd_get_symtab_upper_bound(abfd);
  if (upper < 0) {
    cerr << "bfd_get_symtab_upper_bound failed" << endl;
    return 5;
  }

  asymbol** syms = (asymbol**)(new char[upper]);
  unique_ptr<asymbol*> sweeper2(syms);
  int nsyms = bfd_canonicalize_symtab(abfd, syms);
  if (nsyms < 0) {
    cerr << "bfd_canonicalize_symtab failed" << endl;
    return 6;
  }

  for (auto addr : addrs)
    find_caller(abfd, syms, addr);

  return 0;
}
