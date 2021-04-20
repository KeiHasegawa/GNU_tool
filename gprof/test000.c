#include <stdio.h>
#include <stdlib.h>

void f(int), g(int), h(int);

int main(int argc, char** argv)
{
  if (argc != 4) {
    printf("usage %s number number number\n", argv[0]);
    return 1;
  }
  int N = 1000;
  f(atoi(argv[1])*N);
  g(atoi(argv[2])*N);
  h(atoi(argv[3])*N);
  return 0;
}
