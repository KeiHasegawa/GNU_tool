#include <stdio.h>

float f(float a0, float a1, float a2, float a3, float a4)
{
  return a0 + a1 + a2 + a3 + a4;
}

int main()
{
  printf("hello world %f\n", f(10.0F, 11.0F, 12.0F, 13.0F, 14.0F));
  return 0;
}
