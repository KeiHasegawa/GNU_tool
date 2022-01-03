struct S {
  int a;
  int b;
  int c;
};

int f(struct S x, struct S y, struct S z)
{
  return x.a + x.b + x.c + y.a + y.b + y.c + z.a + z.b + z.c;
}

int main(void)
{
  return 0;
}
