/*
 * Check if declaration with `extern' is recognized
 * after declaration without `extern'.
 */

#include <stdio.h>

int a;         /* declaration without `extern' */
extern int a;  /* declaration with `extern' */
int *b = &a;

int main(void)
{
  extern int a;
  printf("a = %d\n", a = 2);
  printf("*b = %d\n", *b);
  return 0;
}
