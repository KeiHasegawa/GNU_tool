#include <stdio.h>

void f()
{
  throw "Help!";
}

void g()
{
}

int main()
{
  try {
    f();
    g();
  } catch (const char* p) {
    puts(p);
  }
  return 0;
}
