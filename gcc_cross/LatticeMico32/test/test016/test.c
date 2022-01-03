struct S { int i[8]; };

int f(struct S s)
{
  int r = 0;
  for (int i = 0 ; i != sizeof s.i/sizeof s.i[0] ; ++i)
    r += s.i[i];
  return r;
}

int main()
{
  return 0;
}
