#include <stdio.h>

void f(int a, int b)
{
  printf("%d + %d = %d, %d - %d = %d\n", a, b, a+b, a, b, a-b);
}

void g()
{
  printf("%lld %lld\n", 9ll, 10ll);  
}

void h()
{
  printf("%f\n", 1.0);
}

void ff(const char* p, int a, double b)
{
  printf("%s %d %f\n", p, a, b);
}

int main()
{
  char a[] = "hasegawa kei";
  ff(&a[0], 10, 0.5);
  return 0;
}
