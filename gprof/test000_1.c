#include <stdio.h>

void g(int n)
{
  printf("g called with %d\n", n);
  while (--n)
    ;
}
