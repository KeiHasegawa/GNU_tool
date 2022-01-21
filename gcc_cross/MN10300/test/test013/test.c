#include <setjmp.h>

void f(int n, jmp_buf buf)
{
  if (!n)
    longjmp(buf, 123);
  f(n-1, buf);
}

void g(int n)
{
}

int main()
{
  jmp_buf buf;
  int r = setjmp(buf);
  if (!r)
    f(5, buf);
  g(r);
  return 0;
}
