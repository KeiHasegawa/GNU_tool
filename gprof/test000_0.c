#include <stdio.h>

void f(int n)
{
  printf("f called with %d\n", n);
  while (--n)
    ;
}
