#include <stdio.h>
#include "d.h"

void g(int n)
{
  printf("n = %d\n", n);
}

extern int a;

void h(struct S* ps)
{
  printf("ps->m = %d\n", ps->m);
  printf("a = %d\n", a);
}

