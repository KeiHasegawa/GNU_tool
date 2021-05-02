#include <stdio.h>

#define BUFSIZE 128
int buffer[BUFSIZE];
int pointer = 0;

void f(int a)
{
  if (pointer >= BUFSIZE)
    printf("overflow\n");
  else
    buffer[pointer++] = a;
}

int main()
{
  f(1);
  return 0;
}
