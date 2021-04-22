#include <stdint.h>
#include <stdio.h>

#ifndef __CYGWIN__
static FILE* fp = fopen("bb.out", "w");
#endif // __CYGWIN__

extern "C" void _profile_basic_block_()
{
#ifdef __CYGWIN__
  static FILE* fp;
  if (!fp)
    fp = fopen("bb.out", "w");
#endif // __CYGWIN__
#ifdef __x86_64__
  uint64_t addr;
  asm("movq	8(%rbp), %rax");
  asm("movq	%rax, -8(%rbp)");
  fwrite(&addr, sizeof addr, 1, fp);
#else //__x86_64__
  uint32_t addr;
  asm("movl	4(%ebp), %eax");
  asm("mov	%eax, -12(%ebp)");
  fwrite(&addr, sizeof addr, 1, fp);
#endif // __x86_64__
}
