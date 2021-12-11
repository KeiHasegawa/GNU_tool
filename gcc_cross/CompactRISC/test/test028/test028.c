#include <string.h>

struct S {
  int i[16];
};


int main()
{
  struct S s;
  memset(&s, 0, sizeof s);
  return 0;
}
