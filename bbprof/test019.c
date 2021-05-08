#include <stdlib.h>

void f()
{
  exit(1);
}

void g()
{
}

int main()
{
  f();
  g();
  return 0;
}
