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

void fa(int);
void fb(int);
void fc(int);

int main()
{
  f(123);
  fa(456);
  fb(789);
  fc(-1);
  return 0;
}
