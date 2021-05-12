#include <stdio.h>

template<class T>
class Foo
{
public:
  Foo(): b (1000) {}
  void inc () { b++; }

private:
  int b;
};

template class Foo<int>;
template class Foo<char>;

int
main (void)
{
  int i, total;
  Foo<int> counter;

  counter.inc();
  counter.inc();
  total = 0;

  for (i = 0; i < 10; i++)
    total += i;

  int v = total > 100 ? 1 : 2;

  if (total != 45)
    printf ("Failure\n");
  else
    printf ("Success\n");
  return 0;
}
