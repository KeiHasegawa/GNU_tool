#include <stdio.h>

int var = 87654321;

int func(int a)
{
  printf("%s::func called\n", __FILE__);
  int ret = var;
  var = -a;
  return ret;
}
