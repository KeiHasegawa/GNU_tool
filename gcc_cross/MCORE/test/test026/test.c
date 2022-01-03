struct S {
  int a;
  int b;
  int c;
};

struct S f(struct S x, struct S y, struct S z)
{
  x.a += y.a + z.a;
  x.b += y.b + z.b;
  x.c += y.c + z.c;
  return x;
}

int main()
{
  return 0;
}
