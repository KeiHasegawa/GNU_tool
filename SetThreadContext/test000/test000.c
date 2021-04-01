#include <stdio.h>

int my_array[1024];

int main()
{
  puts("start");
  for (int i = 0 ; i != sizeof my_array/sizeof my_array[0] ; ++i)
    my_array[i] = i;
  puts("end");
  return 0;
}
