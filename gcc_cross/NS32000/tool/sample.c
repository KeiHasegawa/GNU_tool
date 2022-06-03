int printf(const char* fmt, ...);

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

void g2(long long a, long long b, long long c, long long d,
	long long e, long long f, long long g, long long h,
	long long i, long long j, long long k, long long l,
	long long m, long long n, long long o, long long p,
	long long q, long long r, long long s, long long t)
{
  printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\n",
	 a, b, c, d,
	 e, f, g, h,
	 i, j, k, l,
	 m, n, o, p,
	 q, r, s, t);
}

void h2(int a, int b, int c, int d,
	int e, int f, int g, int h,
	int i, int j, int k, int l,
	int m, int n, int o, int p,
	int q, int r, int s, int t,
	int u, int v, int w, int x)
{
  printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
	 a, b, c, d,
	 e, f, g, h,
	 i, j, k, l,
	 m, n, o, p,
	 q, r, s, t,
	 u, v, w, x);
}

int test_f3;

void f3(int a)
{
  test_f3 = a;
  printf("test_f3 = %d\n", test_f3);
}

int test_g3;

void g3(void)
{
  printf("test_g3 = %x\n", test_g3);
}

int test_h3 = 456;

void h3(void)
{
  printf("test_h3 = %d\n", test_h3);
}

void f4(char* s)
{
  printf("%s\n", s);
}

int main()
{
  f(5, 6);

  g();
  printf("\n");
  h(1.0);
  ff(9LL);
  char a[] = "hasegawa kei";  
  gg(&a[0], 5, 6.0);
  hh(3.0L);
  f2(1.0, 2.0, 3.0);
  g2(1LL, 2LL, 3LL, 4LL, 5LL, 6LL, 7LL, 8LL, 9LL, 10LL, 11LL, 12LL,
     13LL, 14LL, 15LL, 16LL, 17LL, 18LL, 19LL, 20LL);
  h2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
     21, 22, 23, 24);
  f3(123);
  g3();
  h3();
  return 0;
}

void clear_area(char* b, char* e)
{
  while (b!=e)
    *b++ = 0;
}

void f5(int a, int b)
{
  if (a != b)
    f(a, b);
  else
    g();
}

void g6(char* p, char v)
{
  *p = v;
}
