struct S { int i[9]; };

int f(struct S s, int a0, int a1, int a2)
{
  int r = 0;
  for (int i = 0 ; i != sizeof s.i/sizeof s.i[0] ; ++i)
    r += s.i[i];
  return r + a0 + a1 + a2;
}

int main()
{
  return 0;
}
