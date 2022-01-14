char* _sbrk_ar(int size)
{
  extern char heap;
  static int delta;
  char* ret = &heap + delta;
  delta += size;
  return ret;
}

char* _sbrk_ar2(int size)
{
  extern char heap;
  static int delta;
  char* ret = &heap + delta;
  delta += size;
  return ret;
}

void fa(int a)
{
}
