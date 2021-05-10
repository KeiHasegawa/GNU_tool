int a;

int f()
{
  return 2;
}

void g(int n)
{
}

int main()
{
  if (a) {
    int n;
    n = f();
    g(n);
  }
  return 0;
}
