#include <stdint.h>
#include <stdio.h>

uint32_t clz(uint32_t x)
{
  asm("clz %0" : "=r" (x) : "0" (x));
  return x;
}

int main()
{
  uint32_t x = 0x80000000;
  printf("clz(%x) = %x\n", x, clz(x));
  return 0;
}
