#include <stdint.h>
using namespace std;

struct seg_desc;

struct gdt {
  uint16_t size;
  seg_desc* elem;
};

static_assert(sizeof(gdt) == 8);

struct seg_desc {
  unsigned int limit_lo:16;
  unsigned int base_lo:16;
  unsigned int base_mid:8;
  unsigned int type:4;
  unsigned int segment:1;
  unsigned int dpl:2;  
  unsigned int p:1;
  unsigned int limit_hi:4;
  unsigned int avl:1;
  unsigned int l:1;
  unsigned int d_b:1;
  unsigned int g:1;
  unsigned int base_hi:8;
};

static_assert(sizeof(seg_desc) == 8);

extern seg_desc my_gdt_data[6];

gdt my_gdt = { sizeof my_gdt_data, &my_gdt_data[0] };

struct seg_desc my_gdt_data[] = {
  { .limit_lo = 0 },
  { .limit_lo = 0 },
  { .limit_lo = 0xffff, .type = 0xb, .segment = 1, .dpl = 0, .p = 1,
    .limit_hi = 0xf, .d_b = 1, .g = 1 },
  { .limit_lo = 0xffff, .type = 0x3, .segment = 1, .dpl = 0, .p = 1,
    .limit_hi = 0xf, .d_b = 1, .g = 1 },
  { .limit_lo = 0xffff, .type = 0xb, .segment = 1, .dpl = 0, .p = 1,
    .limit_hi = 0x0, .d_b = 0, .g = 0 },
  { .limit_lo = 0xffff, .type = 0x3, .segment = 1, .dpl = 0, .p = 1,
    .limit_hi = 0x0, .d_b = 0, .g = 0 },
};

int main()
{
  return 0;
}
