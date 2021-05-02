#include <stdio.h>

void f()
{
  printf("f called\n");
}

void g()
{
  printf("g called\n");
}

void h()
{
  printf("h called\n");
}

void test(int n)
{
  switch (n) {
  case 0:
    f();
    break;
  case 1:
    g();
    break;
  case 2:
    h();
    break;
  default:
    printf("default\n");
    break;
  }
}

int main()
{
  test(2);
  test(1);
  return 0;
}
