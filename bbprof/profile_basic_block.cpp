#include <stdint.h>
#include <stdio.h>

static FILE* fp = fopen("bb.out", "w");

extern "C" void _profile_basic_block_()
{
  uint32_t addr;
  asm("movl	4(%ebp), %eax");
  asm("mov	%eax, -12(%ebp)");
  fwrite(&addr, sizeof addr, 1, fp);
}
