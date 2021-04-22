#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>
#include <map>
#include <cassert>
#include <bfd.h>

#ifdef __x86_64__
typedef uint64_t addr_type;
#else // __x86_64__
typedef uint32_t addr_type;
#endif // __x86_64__

inline void collect(asymbol* sym, std::map<addr_type, const char*>* info)
{
  asection* sec = sym->section;
  flagword flags = sec->flags;
  if (!(flags & SEC_CODE))
    return;
  addr_type addr = sec->vma + sym->value;
  if (info->find(addr) == info->end())
    (*info)[addr] = sym->name;
}

int read_prog(const char* aout, std::map<addr_type, const char*>& info)
{
  using namespace std;
  bfd* handle =  bfd_openr(aout, 0);
  if (!handle) {
    cerr << "bfd_openr failed" << endl;
    return -1;
  }

  struct sweeper {
    bfd* m_handle;
    sweeper(bfd* handle) : m_handle{handle} {}
    ~sweeper()
    {
      bfd_close(m_handle);
    }
  } sweeper(handle);

  if (!bfd_check_format(handle, bfd_object)) {
    cerr << "bfd_check_format failed" << endl;
    return -2;
  }

  int upper =  bfd_get_symtab_upper_bound(handle);
  if (upper < 0) {
    cerr << "bfd_get_symtab_upper_bound failed" << endl;
    return -4;
  }

  asymbol** syms = (asymbol**)(new char[upper]);
  unique_ptr<asymbol*> sweeper2(syms);
  int nsyms = bfd_canonicalize_symtab(handle, syms);
  if (nsyms < 0) {
    cerr << "bfd_canonicalize_symtab failed" << endl;
    return -5;
  }

  for_each(&syms[0], &syms[nsyms], bind2nd(ptr_fun(collect), &info));

  return 0;
}

int read_bb(const char* bbout, std::vector<addr_type>& res)
{
  using namespace std;
  ifstream ifs(bbout);
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

inline void
find_caller(addr_type addr, const std::map<addr_type, const char*>* info)
{
  using namespace std;
  auto p = info->upper_bound(addr);
  assert(p != info->begin());
  --p;
  cout << hex << addr << ',' << p->second << endl;
}

int main(int argc, char** argv)
{
  using namespace std;
  if (argc != 3) {
    cerr << "usage % " << argv[0] << " a.out bb.out" << endl;
    return 1;
  }

  map<addr_type, const char*> info;
  if (read_prog(argv[1], info) < 0)
    return 2;

  vector<addr_type> addrs;
  if (read_bb(argv[2], addrs) < 0)
    return 3;

  for_each(begin(addrs), end(addrs), bind2nd(ptr_fun(find_caller), &info));

  return 0;
}
