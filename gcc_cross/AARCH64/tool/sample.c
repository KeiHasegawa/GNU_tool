#include <stdio.h>

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
	  

int main()
{
  hh(1.0L);
  return 0;
}

char* my_memcpy(char* dst, const char* src, int n)
{
  char* r = dst;
  while (n--)
    *dst++ = *src++;
  return r;
}

