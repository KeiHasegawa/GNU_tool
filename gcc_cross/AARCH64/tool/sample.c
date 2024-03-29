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

int test_f4;

void g3(void)
{
  printf("%x\n", test_f4);
}

void f4(int a1, long double a2, float a3, long double a4, int a5, float a6)
{
  printf("%d %Lf %f %Lf %d %f\n", a1, a2, a3, a4, a5, a6);
}

void g4(int a, int b, int c, int d,
	int e, int f, int g, int h,
	int i, int j, int k, int l,
	int m, int n, int o, int p,
	int q, int r, int s, int t,
	int u, int v, int w, int x,
	long double A,
	long double B,
	long double C,
	int D)
{
  printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %Lf %Lf %Lf %d\n",
	 a, b, c, d,
	 e, f, g, h,
	 i, j, k, l,
	 m, n, o, p,
	 q, r, s, t,
	 u, v, w, x,
	 A, B, C, D);
}


void h4(long long a, long long b, long long c, long long d,
	long long e, long long f, long long g, long long h,
	long long i, long long j, long long k, long long l,
	long long m, long long n, long long o, long long p,
	long long q, long long r, long long s, long long t,
	long double A, long double B, long double C, long long D)
{
  printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %Lf %Lf %Lf %lld\n",
	 a, b, c, d,
	 e, f, g, h,
	 i, j, k, l,
	 m, n, o, p,
	 q, r, s, t,
	 A, B, C, D);
}

void f5(double a0, double a1, double a2, double a3,
	double a4, double a5, double a6, double a7,
	double a8, double a9, double a10, double a11,
	long double A, long double B, long double C, double D)
{
  printf("%f %f %f %f %f %f %f %f %f %f %f %f %Lf %Lf %Lf %f\n",
	 a0, a1, a2, a3,
	 a4, a5, a6, a7,
	 a8, a9, a10, a11,
	 A, B, C, D);
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
  f3(1234);
  g3();
  f4(1, 2, 3, 4, 5, 6);
  g4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
     21, 22, 23, 24, 25, 26, 27, 28);
  h4(1LL, 2LL, 3LL, 4LL, 5LL, 6LL, 7LL, 8LL, 9LL, 10LL, 11LL, 12LL,
     13LL, 14LL, 15LL, 16LL, 17LL, 18LL, 19LL, 20LL, 21, 22, 23, 24);
  f5(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0,
     13, 14, 15, 16);
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
