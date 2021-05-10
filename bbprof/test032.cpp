int a = 1;

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
    int n = f();
    g(n);
  }
  return 0;
}
