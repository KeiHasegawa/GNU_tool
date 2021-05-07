#include <stdint.h>
#include <stdio.h>

uint32_t getsp()
{
  uint32_t x;
#if 0
  asm("mov %esp, %0" : "=r" (x));
#endif
#if 1
  asm("mov %esp, %eax");
  asm("mov %eax, -4(%ebp)");
#endif
  return x;
}

int main()
{
  printf("getsp() = %x\n", getsp());
  return 0;
}
