struct S {
  int a;
  int b;
};

int f(int a0, struct S x, int a1, struct S y, int a2, struct S z, int a3,
      struct S u)
{
  return a0 + x.a + x.b + a1 + y.a + y.b + a2 + z.a + z.b + a3 + u.a + u.b;
}

int main()
{
  return 0;
}
