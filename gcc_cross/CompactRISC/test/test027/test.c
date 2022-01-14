#include <string.h>

int f(const char* s)
{
  return strlen(s);
}


int main()
{
  return f("hello world\n");
}
