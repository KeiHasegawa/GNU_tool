struct S {
  int a[2];
};

int f(int a0, struct S s, int a1)
{
  int r = a0 + a1;
  for (int i = 0 ; i != sizeof s.a/sizeof s.a[0] ; ++i)
    r += s.a[i];
  return r;
}

int main()
{
  return 0;
}
