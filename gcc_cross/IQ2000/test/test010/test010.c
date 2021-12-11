/*
 * Check if function definition implicitly `int' assumed
 * is recognized.
 */
#include <stdio.h>

int main()  /* function definition */
{
  f("hello world\n");  /* function call. Here, intentionally not refer
			  declaraion of `f' */
  return 0;
}

void f(const char* msg)
{
  printf("%s", msg);
}
