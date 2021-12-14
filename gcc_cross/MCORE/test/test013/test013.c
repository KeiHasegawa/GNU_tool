void f(int a)
{
  if (a)
    f(a - 1);
}

int main()
{
  f(10);
  return 0;
}
