struct S {
  int a[7];
};

int f(int a0, int a1, struct S s, int a2)
{
  int r = a0 + a1 + a2;
  for (int i = 0 ; i != sizeof s.a/sizeof s.a[0] ; ++i)
    r += s.a[i];
  return r;
}

int main()
{
  return 0;
}
