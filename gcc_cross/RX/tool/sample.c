#include <stdio.h>
#include <stdarg.h>

void f(int a, int b)
{
  printf("%d + %d = %d\n", a, b, a+b);
}

void g()
{
  printf("hello world\n"); 
}

void h(double d)
{
  printf("\n");
  printf("%f\n", d);
}

void ff(long long int lli)
{
  printf("%lld\n", lli);
}

void gg(const char* p, int n, double d)
{
  printf("%s %d %f\n", p, n, d);
}

void hh(long double ld)
{
  printf("%Lf\n", ld);
}

void f2(double a, double b, double c)
{
  printf("%f %f %f\n", a, b, c);
}

void g2(long long a, long long b, long long c)
{
  printf("%lld %lld %lld\n", a, b, c);
}

void h2(int a, int b, int c, int d, int e)
{
  printf("%d %d %d %d %d\n", a, b, c, d, e);
}

int test_f3;

void f3(int a)
{
  test_f3 = a;
  printf("%d\n", test_f3);
}

int test_g3;

void g3(void)
{
  printf("%x\n", test_g3);
}

int test_h3 = 456;

void h3(void)
{
  printf("%d\n", test_h3);
}

int main()
{
  f(5, 6);
  g();
  h(1.0);
  ff(9LL);
  char a[] = "hasegawa kei";
  gg(&a[0], 5, 6.0);
  hh(3.0L);
  f2(1.0, 2.0, 3.0);
  g2(1LL, 2LL, 3LL);
  h2(1, 2, 3, 4, 5);
  f3(123);
  g3();
  h3();
  return 0;
}

void clear_bss(char* b, char* e)
{
  while (b != e)
    *b++ = 0;
}

void f4(int a)
{
  if (a)
    g3();
}
