struct S {
  int a;
  int b;
};

int f(struct S s)
{
  return s.a + s.b;
}

int main()
{
  f((struct S){5, 6});
  return 0;
}