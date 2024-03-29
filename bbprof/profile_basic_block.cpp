#include <stdint.h>
#include <stdio.h>

#ifndef __CYGWIN__
static FILE* fp = fopen("bb.out", "w");
#endif // __CYGWIN__

extern "C" void _profile_basic_block_()
{
#ifdef __x86_64__
  asm("pushq	%rax");
  asm("pushq	%rcx");
  asm("pushq	%rdx");
  asm("pushq	%r8");
  asm("pushq	%r9");
#else  // __x86_64__
  asm("push	%eax");
  asm("push	%edx");  // support C++ exception
#endif // __x86_64__
#ifdef __CYGWIN__
  static FILE* fp;
  if (!fp)
    fp = fopen("bb.out", "w");
#endif // __CYGWIN__
#ifdef __x86_64__
  uint64_t addr;
  asm("movq	8(%rbp), %rax");
  asm("movq	%rax, -8(%rbp)");  // assume that addr is located at -8(%rbp)
  fwrite(&addr, sizeof addr, 1, fp);
  asm("popq	%r9");
  asm("popq	%r8");
  asm("popq	%rdx");
  asm("popq	%rcx");
  asm("popq	%rax");
#else //__x86_64__
  uint32_t addr;
  asm("movl	4(%ebp), %eax");
  asm("mov	%eax, -12(%ebp)");  // assume that addr is located at -12(%ebp)
  fwrite(&addr, sizeof addr, 1, fp);
  asm("pop	%edx");  // support C++ exception
  asm("pop	%eax");
#endif // __x86_64__
}
