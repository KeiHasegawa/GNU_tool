int f()
{
  return 1;
}

int fact(int n)
{
  if (!n)
    return f();
  return n * fact(n-1);
}

int main()
{
  return fact(5);
}
