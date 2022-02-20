int f(int a, int b)
{
  return a + b;
}

int g(int a, int b)
{
  return f(a-1, b+1);
}

int main()
{
  g(5, 6);
  return 0;
}
