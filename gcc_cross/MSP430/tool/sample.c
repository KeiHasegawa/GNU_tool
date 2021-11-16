#include <stdio.h>

void f(int a)
{
  printf("%d\n", -a);
}

int main()
{
  union {
    float f;
    int i;
  } u;
  u.f = 2.0F;
  printf("%08x\n", u.i);
  printf("%f\n", u.f);
  return 0;
}

char* my_memcpy(char* dst, char* src, int n)
{
  char* r = dst;
  while(n--)
    *dst++=*src++;
  return r;
}
