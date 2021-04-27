int f()
{
  return 1;
}

int g()
{
  return 2;
}

int h(int a)
{
  return a ? f() : g();
}

int main()
{
  return h(0);
}
