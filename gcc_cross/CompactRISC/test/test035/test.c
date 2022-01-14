#include <stdarg.h>
#include <stdio.h>

void abort()
{
  asm("	.word	0x80f0");
}

int my_printf(const char* fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  int r = 0;
  for (char c = *fmt ; c = *fmt ; ++fmt) {
    if (c != '%') {
      putchar(c);
      ++r;
      continue;
    }
    c = *++fmt;
    if (c == '%') {
      putchar(c);
      ++r;
      continue;
    }
    if (c == 'd') {
      int n = va_arg(ap, int);
      r += printf("%d", n);
      continue;
    }
    if (c == 'f') {
      double d = va_arg(ap, double);
      r += printf("%f", d);
      continue;
    }
    if (c == 'l') {
      c = *++fmt;
      if (c == 'l') {
	c = *++fmt;
	if (c == 'd') {
	  long long int lli = va_arg(ap, long long int);
	  r += printf("%lld", lli);
	  continue;
	}
      }
      if (c == 'd') {
	long int li = va_arg(ap, long int);
	r += printf("%li", li);
	continue;
      }
      abort();
    }
    if (c == 's') {
      char* p = va_arg(ap, char*);
      r += printf("%s", p);
      continue;
    }
    if (c == 'L') {
      c = *++fmt;
      if (c == 'f') {
	long double ld = va_arg(ap, long double);
	r += printf("%Lf", ld);
	continue;
      }
    }
    abort();
  }
  va_end(ap);
  return r;
}

void f(int a, int b)
{
  my_printf("%d + %d = %d\n", a, b, a+b);
}

void g()
{
  my_printf("hello world\n"); 
}

void h(double d)
{
  my_printf("\n");
  my_printf("%f\n", d);
}

void ff(long long int lli)
{
  my_printf("%lld\n", lli);
}

void ff2(long int li)
{
  my_printf("%ld\n", li);
}

void gg(const char* p, int n, double d)
{
  my_printf("%s %d %f\n", p, n, d);
}

void hh(long double ld)
{
  my_printf("%Lf\n", ld);
}

int main()
{
  f(5, 6);
  g();
  h(0.5);
  ff(9LL);
  ff2(10L);
  char a[] = "hasegawa kei";
  gg(&a[0], 7, 2.0);
  hh(1.0L);
  my_printf("%d\n", 123);
  return 0;
}
