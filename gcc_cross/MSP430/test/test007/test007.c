int f()
{
  return 1;
}

int f1(int n)
{
  return f();
}

int f2(int n)
{
  return f1(n-1);
}

int f3(int n)
{
  return f2(n-1);
}

int f4(int n)
{
  return f3(n-1);
}

int main()
{
  return f4(5);
}
