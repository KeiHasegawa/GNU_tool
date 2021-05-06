#include <stdlib.h>

int f(int a)
{
  if (a) {
    exit(1);
  }
  return a + 5;
}

int main()
{
  f(1);
  return 0;
}
