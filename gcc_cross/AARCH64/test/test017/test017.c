int f(int a, int b)
{
  return a + b;
}

int g(int a, int b)
{
  return f(a-1, b-1);
}

int main()
{
  return g(5, 6);
}
