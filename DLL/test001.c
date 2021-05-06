#include <stdio.h>

extern int __attribute__((dllimport)) var;

int func(int);

int main()
{
  func(3456);
  printf("var = %d\n", var);
  return 0;
}
