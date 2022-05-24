int f(int a, int b)
{
  return a + b;
}

int main()
{
  return f(5, 6);
}

int* g()
{
  extern int stack;
  return &stack;
}

int h()
{
  return 0x12345678;
}

int abcdefg = 123;

int* ff()
{
  return &abcdefg;
}

const char* gg()
{
  return "hasegawa kei";
}

int hh()
{
  return abcdefg;
}

int* ptr = &abcdefg;

int f3()
{
  return *ptr;
}
