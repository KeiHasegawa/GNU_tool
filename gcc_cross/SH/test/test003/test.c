#include <stdio.h>

typedef double T;
T f(T d4, T d6, T d8, T d10, T s0, T s1)
{
  return d4 + d6 + d8 + d10 + s0 + s1;
}

int main()
{
  printf("%f\n", f(1,2,3,4,5,6));
  return 0;
}
