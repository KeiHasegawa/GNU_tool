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

void g2(long long r3, long long r4, long long r5, long long r6,
	long long r7, long long r8, long long r9, long long r10,
	long long r11, long long r12, long long r13, long long r14,
	long long r15, long long r16, long long r17, long long r18,
	long long r19, long long r20, long long r21, long long r22,
	long long r23, long long r24, long long r25, long long r26,
	long long r27, long long r28, long long r29, long long r30,
	long long r31, long long r32, long long r33, long long r34,
	long long r35, long long r36, long long r37, long long r38,
	long long r39, long long r40, long long r41, long long r42,
	long long r43, long long r44, long long r45, long long r46,
	long long r47, long long r48, long long r49, long long r50,
	long long r51, long long r52, long long r53, long long r54,
	long long r55, long long r56, long long r57, long long r58,
	long long r59, long long r60, long long r61, long long r62,
	long long r63, long long r64, long long r65, long long r66,
	long long r67, long long r68, long long r69, long long r70,
	long long r71, long long r72, long long r73, long long r74,
	long long r75, long long r76, long long r77, long long r78,
	long long r79, long long r80, long long r81, long long r82)
{
  printf("%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld \
%lld %lld %lld %lld\n",
	 r3, r4, r5, r6,
	 r7, r8, r9, r10,
	 r11, r12, r13, r14,
	 r15, r16, r17, r18,
	 r19, r20, r21, r22,
	 r23, r24, r25, r26,
	 r27, r28, r29, r30,
	 r31, r32, r33, r34,
	 r35, r36, r37, r38,
	 r39, r40, r41, r42,
	 r43, r44, r45, r46,
	 r47, r48, r49, r50,
	 r51, r52, r53, r54,
	 r55, r56, r57, r58,
	 r59, r60, r61, r62,
	 r63, r64, r65, r66,
	 r67, r68, r69, r70,
	 r71, r72, r73, r74,
	 r75, r76, r77, r78,
	 r79, r80, r81, r82);
}

void h2(int r3, int r4, int r5, int r6,
	int r7, int r8, int r9, int r10,
	int r11, int r12, int r13, int r14,
	int r15, int r16, int r17, int r18,
	int r19, int r20, int r21, int r22,
	int r23, int r24, int r25, int r26,
	int r27, int r28, int r29, int r30,
	int r31, int r32, int r33, int r34,
	int r35, int r36, int r37, int r38,
	int r39, int r40, int r41, int r42,
	int r43, int r44, int r45, int r46,
	int r47, int r48, int r49, int r50,
	int r51, int r52, int r53, int r54,
	int r55, int r56, int r57, int r58,
	int r59, int r60, int r61, int r62,
	int r63, int r64, int r65, int r66,
	int r67, int r68, int r69, int r70,
	int r71, int r72, int r73, int r74,
	int r75, int r76, int r77, int r78,
	int r79, int r80, int r81, int r82)
{
  printf("%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d \
%d %d %d %d\n",
	 r3, r4, r5, r6,
	 r7, r8, r9, r10,
	 r11, r12, r13, r14,
	 r15, r16, r17, r18,
	 r19, r20, r21, r22,
	 r23, r24, r25, r26,
	 r27, r28, r29, r30,
	 r31, r32, r33, r34,
	 r35, r36, r37, r38,
	 r39, r40, r41, r42,
	 r43, r44, r45, r46,
	 r47, r48, r49, r50,
	 r51, r52, r53, r54,
	 r55, r56, r57, r58,
	 r59, r60, r61, r62,
	 r63, r64, r65, r66,
	 r67, r68, r69, r70,
	 r71, r72, r73, r74,
	 r75, r76, r77, r78,
	 r79, r80, r81, r82);
}

void hh2(long r3, long r4, long r5, long r6,
	long r7, long r8, long r9, long r10,
	long r11, long r12, long r13, long r14,
	long r15, long r16, long r17, long r18,
	long r19, long r20, long r21, long r22,
	long r23, long r24, long r25, long r26,
	long r27, long r28, long r29, long r30,
	long r31, long r32, long r33, long r34,
	long r35, long r36, long r37, long r38,
	long r39, long r40, long r41, long r42,
	long r43, long r44, long r45, long r46,
	long r47, long r48, long r49, long r50,
	long r51, long r52, long r53, long r54,
	long r55, long r56, long r57, long r58,
	long r59, long r60, long r61, long r62,
	long r63, long r64, long r65, long r66,
	long r67, long r68, long r69, long r70,
	long r71, long r72, long r73, long r74,
	long r75, long r76, long r77, long r78,
	long r79, long r80, long r81, long r82)
{
  printf("%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld \
%ld %ld %ld %ld\n",
	 r3, r4, r5, r6,
	 r7, r8, r9, r10,
	 r11, r12, r13, r14,
	 r15, r16, r17, r18,
	 r19, r20, r21, r22,
	 r23, r24, r25, r26,
	 r27, r28, r29, r30,
	 r31, r32, r33, r34,
	 r35, r36, r37, r38,
	 r39, r40, r41, r42,
	 r43, r44, r45, r46,
	 r47, r48, r49, r50,
	 r51, r52, r53, r54,
	 r55, r56, r57, r58,
	 r59, r60, r61, r62,
	 r63, r64, r65, r66,
	 r67, r68, r69, r70,
	 r71, r72, r73, r74,
	 r75, r76, r77, r78,
	 r79, r80, r81, r82);
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
  g2(3, 4, 5, 6,
     7, 8, 9, 10,
     11, 12, 13, 14,
     15, 16, 17, 18,
     19, 20, 21, 22,
     23, 24, 25, 26,
     27, 28, 29, 30,
     31, 32, 33, 34,
     35, 36, 37, 38,
     39, 40, 41, 42,
     43, 44, 45, 46,
     47, 48, 49, 50,
     51, 52, 53, 54,
     55, 56, 57, 58,
     59, 60, 61, 62,
     63, 64, 65, 66,
     67, 68, 69, 70,
     71, 72, 73, 74,
     75, 76, 77, 78,
     79, 80, 81, 82);
  h2(3, 4, 5, 6,
     7, 8, 9, 10,
     11, 12, 13, 14,
     15, 16, 17, 18,
     19, 20, 21, 22,
     23, 24, 25, 26,
     27, 28, 29, 30,
     31, 32, 33, 34,
     35, 36, 37, 38,
     39, 40, 41, 42,
     43, 44, 45, 46,
     47, 48, 49, 50,
     51, 52, 53, 54,
     55, 56, 57, 58,
     59, 60, 61, 62,
     63, 64, 65, 66,
     67, 68, 69, 70,
     71, 72, 73, 74,
     75, 76, 77, 78,
     79, 80, 81, 82);
  hh2(3, 4, 5, 6,
     7, 8, 9, 10,
     11, 12, 13, 14,
     15, 16, 17, 18,
     19, 20, 21, 22,
     23, 24, 25, 26,
     27, 28, 29, 30,
     31, 32, 33, 34,
     35, 36, 37, 38,
     39, 40, 41, 42,
     43, 44, 45, 46,
     47, 48, 49, 50,
     51, 52, 53, 54,
     55, 56, 57, 58,
     59, 60, 61, 62,
     63, 64, 65, 66,
     67, 68, 69, 70,
     71, 72, 73, 74,
     75, 76, 77, 78,
     79, 80, 81, 82);
  f3(123);
  g3();
  h3();
  return 0;
}
#if 0
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


void h4(char* s)
{
  printf("%s\n", s);
}
#endif
