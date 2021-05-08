#include <stdio.h>

void f()
{
  throw "Help!";
}

int main()
{
  try {
    f();
  } catch (const char* p) {
    puts(p);
  }
  return 0;
}
