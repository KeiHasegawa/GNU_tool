#include <stdint.h>
#include <stdio.h>

uint16_t ntohs(uint16_t x)
{
  asm("xchgb %b0,%h0" : "=Q" (x) : "0" (x));
  return x;
}

int main()
{
  uint16_t x = 0x1234;
  printf("ntohs(%x) = %x\n", x, ntohs(x));
  return 0;
}
