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
  struct S r = f((struct S){1, 2, 3}, (struct S){4, 5, 6}, (struct S){7, 8, 9});
  return 0;
}
