int f0(int a, int b)
{
  return a + b;
}

int f1(int a, int b)
{
  return f0(a-1, b+1);
}

int f2(int a, int b)
{
  return f1(a-1, b+1);
}

int f3(int a, int b)
{
  return f2(a-1, b+1);
}

int f4(int a, int b)
{
  return f3(a-1, b+1);
}

int f5(int a, int b)
{
  return f4(a-1, b+1);
}

int f6(int a, int b)
{
  return f5(a-1, b+1);
}

int f7(int a, int b)
{
  return f6(a-1, b+1);
}

int main()
{
  return f7(5, 6);
}
