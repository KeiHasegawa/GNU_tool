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

void f3(const char* fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  vprintf(fmt, ap);
  va_end(ap);
}

int main()
{
  f3("%f\n", 1.0);
  return 0;
}


char* my_memcpy(char* dst, const char* src, int n)
{
  char* r = dst;
  while (n--)
    *dst++=*src++;
  return r;
}

char* my_memset(char* dst, int c, int n)
{
  char* r = dst;
  while (n--)
    *dst++ = c;
  return r;
}

int my_strlen(const char* s)
{
  int n = 0;
  while (*s++)
    ++n;
  return n;
}
