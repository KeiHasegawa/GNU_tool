#include <stdio.h>

void f()
{
  printf("f called\n");
}

void g()
{
  printf("g called\n");
}

void h(int a)
{
  a ? f() : g();
  printf("leave `h'\n");
}

int main()
{
  h(0);
  return 0;
}
