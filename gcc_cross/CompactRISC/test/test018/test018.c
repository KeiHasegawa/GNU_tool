char* _sbrk_r(int size)
{
  extern char heap;
  static int delta;
  char* ret = &heap + delta;
  delta += size;
  return ret;
}

char* _sbrk_r2(int size)
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
  _sbrk_r(456);
  _sbrk_r2(789);
  return 0;
}
