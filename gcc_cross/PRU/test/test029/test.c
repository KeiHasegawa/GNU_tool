struct S {
  int a[3];
};

int f(struct S s)
{
  int r = 0;
  for (int i = 0 ; i != sizeof s.a/sizeof s.a[0] ; ++i)
    r += s.a[i];
  return r;
}

int main()
{
  return 0;
}
