int a;

int f()
{
  return 2;
}

void g(int n)
{
}

int N;

int main()
{
  if (a) {
    N = f();
    g(N);
  }
  return 0;
}
