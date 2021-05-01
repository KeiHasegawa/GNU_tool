#include <stdio.h>

int f()
{
	putc('f', stdout); 
	putc('\n', stdout); 
	return 2;
}

int g()
{
  return 3;
}

int h(int a)
{
  return a ? f() : g();
}

int main()
{
  printf("%d\n", h(1));
  return 0;
}
