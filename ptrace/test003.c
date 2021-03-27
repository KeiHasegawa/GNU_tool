#include <stdio.h>

int a[1024];

int main()
{
  puts("start");
  for (int i = 0 ; i != sizeof a/sizeof a[0] ; ++i)
    a[i] = i;
  puts("end");
  return 0;
}
