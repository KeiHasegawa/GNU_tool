#include "d.h"

int a;

void g(int);

void f()
{
  g(a);
  g(X);
}

int f2(location loc)
{
  return loc;
}
