struct S {
  int a;
  int b;
};

int f(struct S s)
{
  s.a = 1;
  s.b = 2;
  return s.a + s.b;
}

int main()
{
  struct S s = {5, 6};
  return 0;
}
