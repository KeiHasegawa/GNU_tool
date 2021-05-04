#include <stdio.h>

struct X {
  X()
  {
    printf("X::X() called\n");
  }
  ~X()
  {
    printf("X::~X() called\n");
  }
};

X obj;

int main()
{
  printf("main called\n");
  return 0;
}
