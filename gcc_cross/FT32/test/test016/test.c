/*
 * Check address and indirection operator works well outside function
 * or in constantant-expression.
 */
#include <stdio.h>

int test_000;
int* test_001 = &test_000;
int* test_002 = &*&test_000;

void test00(void)
{
  printf("`test00' called\n");
  test_000 = 1234;
  printf("%d %d\n", *test_001, *test_002);
}

short int test_100[10];
short int (*test_101)[] = &test_100;
short int *test_102 = &test_100[0];
short int *test_103 = test_100;
short int *test_104 = &*test_100;

void test01(void)
{
  printf("`test01' called\n");
  int n = sizeof test_100 / sizeof test_100[0];
  for ( short int* p = &test_100[0] ; p != &test_100[n] ; ++p )
    *p = n + (p - &test_100[0]);

  for ( int i = 0 ; i < n ; ++i )
    printf(" %d", (*test_101)[i]);
  printf("\n");

  for ( int i = 0 ; i < n ; ++i )
    printf(" %d", test_102[i]);
  printf("\n");

  for ( int i = 0 ; i < n ; ++i )
    printf(" %d", test_103[i]);
  printf("\n");

  for ( int i = 0 ; i < n ; ++i )
    printf(" %d", test_104[i]);
  printf("\n");
}

union U {
  char snode[10];
  int inode;
  long double fnode;
};

struct S {
  int flag;
  union U u;
};

struct S test_200[] = {
  { 's', { .snode = "program"} },
  { 'i', { .inode = 3 } },
  { 'f', { .fnode = 4 } },
  { 'f', { .fnode = 5 } },
  { 'i', { .inode = 6 } },
  { 's', { .snode = "language"} },
};

char* test_201 = &test_200[0].u.snode[0];
union U* test_202 = &test_200[1].u;
struct S* test_203 = &test_200[2];
struct S* test_204 = &*test_200 + sizeof test_200 / sizeof *test_200;

void test02(void)
{
  printf("`test02' called\n");
  printf("\"%s\"\n", test_201);
  printf("%d\n", test_202->inode);
  printf("'%c' %Lf\n", test_203->flag, test_203->u.fnode);

  for ( struct S* p = test_200 ; p != test_204 ; ++p ){
    switch ( p->flag ){
    case 's': printf("%s\n", p->u.snode); break;
    case 'i': printf("%d\n", p->u.inode); break;
    case 'f': printf("%Lf\n", p->u.fnode); break;
    }
  }
}

int main(void)
{
  test00();
  test01();
  test02();
  return 0;
}
