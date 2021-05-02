#include <stdio.h>

int f(int a, int b)
{
  if (a < b)
    printf("%d < %d\n", a, b);
  else
    printf("%d >= %d\n", a, b);
}

int main()
{
  f(7, 3);
  return 0;
}

