/*
 * floating literal used outside function
 */
#include <stdio.h>

float test00_f1 = 1.0F;
double test00_d1 = 1.0;
long double test00_ld1 = 1.0L;

float test00_f2 = 2.0L;
double test00_d2 = 2.0F;
long double test00_ld2 = 2.0F;

void test00(void)
{
  printf("`test00' called\n");
  printf("%f\n", test00_f1);
  printf("%f\n", test00_d1);
  printf("%Lf\n", test00_ld1);
  printf("%f\n", test00_f2);
  printf("%f\n", test00_d2);
  printf("%Lf\n", test00_ld2);
}

float test01_f1 = +3.0F;
double test01_d1 = +3.0;
long double test01_ld1 = +3.0L;

float test01_f2 = -4.0F;
double test01_d2 = -4.0;
long double test01_ld2 = -4.0L;

int test01_f3 = !5.0F;
int test01_d3 = !5.0;
int test01_ld3 = !5.0L;

int test01_f4 = sizeof 6.0F;
int test01_d4 = sizeof 6.0;
int test01_ld4 = sizeof 6.0L;

void test01(void)
{
  printf("`test01' called\n");
  printf("%f\n", test01_f1);
  printf("%f\n", test01_d1);
  printf("%Lf\n", test01_ld1);
  printf("%f\n", test01_f2);
  printf("%f\n", test01_d2);
  printf("%Lf\n", test01_ld2);
  printf("%d\n", test01_f3);
  printf("%d\n", test01_d3);
  printf("%d\n", test01_ld3);
  printf("%d\n", test01_f4);
  printf("%d\n", test01_d4);
  printf("%d\n", test01_ld4);
}

char test02_f1 = (char)7.0F;
char test02_d1 = (char)7.0;
char test02_ld1 = (char)7.0L;
signed char test02_f2 = (signed char)8.0F;
signed char test02_d2 = (signed char)8.0;
signed char test02_ld2 = (signed char)8.0L;
unsigned char test02_f3 = (unsigned char)9.0F;
unsigned char test02_d3 = (unsigned char)9.0;
unsigned char test02_ld3 = (unsigned char)9.0L;
short int test02_f4 = (short int)10.0F;
short int test02_d4 = (short int)10.0;
short int test02_ld4 = (short int)10.0L;
unsigned short int test02_f5 = (unsigned short int)11.0F;
unsigned short int test02_d5 = (unsigned short int)11.0;
unsigned short int test02_ld5 = (unsigned short int)11.0L;
int test02_f6 = (int)12.0F;
int test02_d6 = (int)12.0;
int test02_ld6 = (int)12.0L;
unsigned int test02_f7 = (unsigned int)13.0F;
unsigned int test02_d7 = (unsigned int)13.0;
unsigned int test02_ld7 = (unsigned int)13.0L;
long int test02_f8 = (long int)14.0F;
long int test02_d8 = (long int)14.0;
long int test02_ld8 = (long int)14.0L;
unsigned long int test02_f9 = (unsigned long int)15.0F;
unsigned long int test02_d9 = (unsigned long int)15.0;
unsigned long int test02_ld9 = (unsigned long int)15.0L;
long long int test02_f10 = (long long int)16.0F;
long long int test02_d10 = (long long int)16.0;
long long int test02_ld10 = (long long int)16.0L;
unsigned long long int test02_f11 = (unsigned long long int)17.0F;
unsigned long long int test02_d11 = (unsigned long long int)17.0;
unsigned long long int test02_ld11 = (unsigned long long int)17.0L;
float test02_f12 = (float)18.0F;
float test02_d12 = (float)18.0;
float test02_ld12 = (float)18.0L;
double test02_f13 = (double)19.0F;
double test02_d13 = (double)19.0;
double test02_ld13 = (double)19.0L;
long double test02_f14 = (long double)20.0F;
long double test02_d14 = (long double)20.0;
long double test02_ld14 = (long double)20.0L;

void test02(void)
{
  printf("`test02' called\n");
  printf("%d\n", test02_f1);
  printf("%d\n", test02_d1);
  printf("%d\n", test02_ld1);
  printf("%d\n", test02_f2);
  printf("%d\n", test02_d2);
  printf("%d\n", test02_ld2);
  printf("%d\n", test02_f3);
  printf("%d\n", test02_d3);
  printf("%d\n", test02_ld3);
  printf("%d\n", test02_f4);
  printf("%d\n", test02_d4);
  printf("%d\n", test02_ld4);
  printf("%d\n", test02_f5);
  printf("%d\n", test02_d5);
  printf("%d\n", test02_ld5);
  printf("%d\n", test02_f6);
  printf("%d\n", test02_d6);
  printf("%d\n", test02_ld6);
  printf("%d\n", test02_f7);
  printf("%d\n", test02_d7);
  printf("%d\n", test02_ld7);
  printf("%ld\n", test02_f8);
  printf("%ld\n", test02_d8);
  printf("%ld\n", test02_ld8);
  printf("%lu\n", test02_f9);
  printf("%lu\n", test02_d9);
  printf("%lu\n", test02_ld9);
  printf("%lld\n", test02_f10);
  printf("%lld\n", test02_d10);
  printf("%lld\n", test02_ld10);
  printf("%lld\n", test02_f11);
  printf("%lld\n", test02_d11);
  printf("%lld\n", test02_ld11);
  printf("%f\n", test02_f12);
  printf("%f\n", test02_d12);
  printf("%f\n", test02_ld12);
  printf("%f\n", test02_f13);
  printf("%f\n", test02_d13);
  printf("%f\n", test02_ld13);
  printf("%Lf\n", test02_f14);
  printf("%Lf\n", test02_d14);
  printf("%Lf\n", test02_ld14);
}

float test03_f1 = 3.0F * 7.0F;
double test03_d1 = 3.0 * 7.0;
long double test03_ld1 = 3.0L * 7.0L;
float test03_f2 = 44.0F / 2.0F;
double test03_d2 = 44.0 / 2.0;
long double test03_ld2 = 44.0L / 2.0L;

void test03(void)
{
  printf("`test03' is called\n");
  printf("%f\n", test03_f1);
  printf("%f\n", test03_d1);
  printf("%Lf\n", test03_ld1);
  printf("%f\n", test03_f2);
  printf("%f\n", test03_d2);
  printf("%Lf\n", test03_ld2);
}

float test04_f1 = 11.0F + 12.0F;
double test04_d1 = 11.0 + 12.0;
long double test04_ld1 = 11.0L + 12.0L;
float test04_f2 = 10.0F - 34.0F;
double test04_d2 = 10.0 - 34.0;
long double test04_ld2 = 10.0L - 34.0L;

void test04(void)
{
  printf("`test04' is called\n");
  printf("%f\n", test04_f1);
  printf("%f\n", test04_d1);
  printf("%Lf\n", test04_ld1);
  printf("%f\n", test04_f2);
  printf("%f\n", test04_d2);
  printf("%Lf\n", test04_ld2);
}

int test05_f1 = 1.0F < 2.0F;
int test05_d1 = 1.0 < 2.0;
int test05_ld1 = 1.0L < 2.0L;
int test05_f2 = 1.0F > 2.0F;
int test05_d2 = 1.0 > 2.0;
int test05_ld2 = 1.0L > 2.0L;
int test05_f3 = 1.0F <= 2.0F;
int test05_d3 = 1.0 <= 2.0;
int test05_ld3 = 1.0L <= 2.0L;
int test05_f4 = 1.0F >= 2.0F;
int test05_d4 = 1.0 >= 2.0;
int test05_ld4 = 1.0L >= 2.0L;

void test05(void)
{
  printf("`test05' is called\n");
  printf("%d\n", test05_f1);
  printf("%d\n", test05_d1);
  printf("%d\n", test05_ld1);
  printf("%d\n", test05_f2);
  printf("%d\n", test05_d2);
  printf("%d\n", test05_ld2);
  printf("%d\n", test05_f3);
  printf("%d\n", test05_d3);
  printf("%d\n", test05_ld3);
  printf("%d\n", test05_f4);
  printf("%d\n", test05_d4);
  printf("%d\n", test05_ld4);
}

int test06_f1 = 1.0F == 2.0F;
int test06_d1 = 1.0 == 2.0;
int test06_ld1 = 1.0L == 2.0L;
int test06_f2 = 1.0F != 2.0F;
int test06_d2 = 1.0 != 2.0;
int test06_ld2 = 1.0L != 2.0L;

void test06(void)
{
  printf("`test06' is called\n");
  printf("%d\n", test06_f1);
  printf("%d\n", test06_d1);
  printf("%d\n", test06_ld1);
  printf("%d\n", test06_f2);
  printf("%d\n", test06_d2);
  printf("%d\n", test06_ld2);
}

int test07_f1 = 0.0F && 2.0F;
int test07_d1 = 0.0 && 2.0;
int test07_ld1 = 0.0L && 2.0L;
int test07_f2 = 0.0F || 2.0F;
int test07_d2 = 0.0 || 2.0;
int test07_ld2 = 0.0L || 2.0L;

void test07(void)
{
  printf("`test07' is called\n");
  printf("%d\n", test07_f1);
  printf("%d\n", test07_d1);
  printf("%d\n", test07_ld1);
  printf("%d\n", test07_f2);
  printf("%d\n", test07_d2);
  printf("%d\n", test07_ld2);
}

float test08_f1 = 24.0F ? 25.0F : 26.0F;
double test08_d1 = 24.0 ? 25.0 : 26.0;
long double test08_ld1 = 24.0L ? 25.0L : 26.0L;

void test08(void)
{
  printf("`test08' is called\n");
  printf("%f\n", test08_f1);
  printf("%f\n", test08_d1);
  printf("%Lf\n", test08_ld1);
}

#ifndef __GNUC__
float test09_f1 = (25.0F, 26.0F);
double test09_d1 = (25.0, 26.0);
long double test09_ld1 = (25.0L, 26.0L);

void test09(void)
{
  printf("`test09' is called\n");
  printf("%f\n", test09_f1);
  printf("%f\n", test09_d1);
  printf("%Lf\n", test09_ld1);
}
#endif

int main(void)
{
  test00();
  test01();
  test02();
  test03();
  test04();
  test05();
  test06();
  test07();
  test08();
#ifndef __GNUC__
  test09();
#endif  
  return 0;
}
