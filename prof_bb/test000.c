int f(int a, int b, int c)
{
  return a ? b : c;
}

int main()
{
  return f(0, 1, 2);
}
