struct S {
  int a;
  int b;
};

struct S f(struct S x, struct S y, struct S z)
{
  x.a += y.a + z.a;
  x.b += y.b + z.b;
  return x;
}

int main()
{
  f((struct S){1, 2}, (struct S){3, 4}, (struct S){5, 6});
  return 0;
}
