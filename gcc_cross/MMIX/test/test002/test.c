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

int a;

int h()
{
  return 0x1000;
}

