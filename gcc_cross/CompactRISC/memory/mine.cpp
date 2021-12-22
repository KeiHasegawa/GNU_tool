#include "config.h"
#include "bfd.h"
#include "sim-main.h"

#include <vector>
#include <algorithm>
#include <functional>

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


