#include "config.h"
#include "bfd.h"
#include "sim-main.h"

#include <map>
#include <vector>
#include <algorithm>

std::map<int, decoded_inst> cache;

extern "C" decoded_inst* get_cache(int pc)
{
  using namespace std;
  auto p = cache.find(pc);
  if (p != end(cache))
    return &p->second;
  return nullptr;
}

extern "C" void set_cache(int pc, decoded_inst* inst)
{
  cache[pc] = *inst;
}

std::vector<std::pair<bfd_vma, bfd_size_type> > code_areas;

bool match(std::pair<bfd_vma, bfd_size_type> p, bfd_vma x)
{
  auto addr = p.first;
  auto size = p.second;
  return addr <= x && x < addr + size;
}

extern "C" bool code_area(bfd_vma addr)
{
  auto p = find_if(begin(code_areas), end(code_areas),
		   bind2nd(ptr_fun(match), addr));
  return p != end(code_areas);
}

extern "C" void set_code_area(bfd_vma addr, bfd_size_type size)
{
  using namespace std;
  code_areas.push_back(make_pair(addr, size));
}

