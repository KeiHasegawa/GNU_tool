#include <stdio.h>

int __attribute__((dllexport)) var = 12345678;

int __attribute__((dllexport)) func(int a)
{
  printf("%s::func called\n", __FILE__);
  int ret = var;
  var = a;
  return var;
}
