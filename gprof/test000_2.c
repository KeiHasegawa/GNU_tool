#include <stdio.h>

void h(int n)
{
  printf("h called with %d\n", n);
  while (--n)
    ;
}
