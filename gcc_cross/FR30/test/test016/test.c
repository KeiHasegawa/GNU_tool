struct S {
  int a;
  int b;
};

struct S f(struct S u, struct S v, struct S w,
	   struct S x, struct S y, struct S z)
{
  u.a += v.a + w.a + x.a + y.a + z.a;
  u.b += v.b + w.b + x.b + y.b + z.b;
  return u;
}

int main()
{
  return 0;
}
