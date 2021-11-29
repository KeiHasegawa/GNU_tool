/*
 * Check if conversions from `float' to integer are well done.
 */
#include <stdio.h>

/* from `float' to `char' */
void test00(float y)
{
  printf("`test00' called\n");
  char x = y;
  printf("%d\n", x);
}

/* from `float' to `signed char' */
void test01(float y)
{
  printf("`test01' called\n");
  signed char x = y;
  printf("%d\n", x);
}

/* from `float' to `unsigned char' */
void test02(float y)
{
  printf("`test02' called\n");
  unsigned char x = y;
  printf("%d\n", x);
}

/* from `float' to `short int' */
void test03(float y)
{
  printf("`test03' called\n");
  short int x = y;
  printf("%d\n", x);
}

/* from `float' to `unsigned short int' */
void test04(float y)
{
  printf("`test04' called\n");
  unsigned short int x = y;
  printf("%d\n", x);
}

/* from `float' to `int' */
void test05(float y)
{
  printf("`test05' called\n");
  int x = y;
  printf("%d\n", x);
}

/* from `float' to `unsigned int' */
void test06(float y)
{
  printf("`test06' called\n");
  unsigned int x = y;
  printf("%d\n", x);
}

/* from `float' to `long int' */
void test07(float y)
{
  printf("`test07' called\n");
  long int x = y;
  printf("%ld\n", x);
}

/* from `float' to `unsigned long int' */
void test08(float y)
{
  printf("`test08' called\n");
  unsigned long int x = y;
  printf("%lu\n", x);
}

/* from `float' to `long long int' */
void test09(float y)
{
  printf("`test09' called\n");
  long long int x = y;
  printf("%lld\n", x);
}

/* from `float' to `unsigned long long int' */
void test10(float y)
{
  printf("`test10' called\n");
  unsigned long long int x = y;
  printf("%llu\n", x);
}

void f(float y)
{
  printf("`f' called with %f\n", y);
  test00(y);
  test01(y);
  test02(y);
  test03(y);
  test04(y);
  test05(y);
  test06(y);
  test07(y);
  test08(y);
  test09(y);
  test10(y);
}

int main(void)
{
  float a[] = {
    -128.5F, -128.0F, -127.5F, 126.5F, 127.0F, 127.5F,

    254.5F, 255.0F, 255.5F,

    -32768.5F, -32768.0F, -32767.5F, 32766.5F, 32767.0F, 32767.5F,

    65534.5F, 65535.0F, 65535.5F,

    -2147483648.5F, -2147483648.0F, -2147483647.5F,
    2147483646.5F, 2147483647.0F, 2147483647.5F,

    4294967294.5F, 4294967295.0F, 4294967295.5F,

    -9223372036854775808.5F, -9223372036854775808.0F, -9223372036854775807.5F,
    9223372036854775806.5F, 9223372036854775807.0F, 9223372036854775807.5F,

    18446744073709551614.5F, 18446744073709551615.0F, 18446744073709551615.5F,
  };
  for ( int i = 0 ; i < sizeof a/sizeof a[0] ; ++i )
    f(a[i]);
  return 0;
}
