#include <stdint.h>
#include <stdio.h>

uint32_t ntohl(uint32_t x)
{
  asm("bswap %0" : "=r" (x) : "0" (x));
  return x;
}

int main()
{
  uint32_t x = 0x12345678;
  printf("nohl(%x) = %x\n", x, ntohl(x));
  return 0;
}
