#include <stdio.h>

int f(int n)
{
  int s = 0;
  while (n--)
    s += n;
  return s;
}

int main()
{
  printf("%d\n", f(10));
  return 0;
}
