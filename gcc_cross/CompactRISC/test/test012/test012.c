char* _sbrk_r(int size)
{
  extern char heap;
  static int delta;
  char* ret = &heap + delta;
  delta += size;
  return ret;
}

void f(int a)
{
}

int main()
{
  f(123);
  return 0;
}
