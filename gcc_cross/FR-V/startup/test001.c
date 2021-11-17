int x;

int f(int a, int b)
{
  return x = a + b;
}

int main()
{
  f(5, 6);
  return 0;
}
