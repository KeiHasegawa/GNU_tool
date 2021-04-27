int f()
{
  return 4;
}

int g()
{
  return 5;
}

int h(int a)
{
  return a ? f() : g();
}

int main()
{
  return h(3);
}
