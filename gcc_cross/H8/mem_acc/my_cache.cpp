#include "sim-main.h"

#include <map>

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


