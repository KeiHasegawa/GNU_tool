typedef long long int T;

struct S {
  T a;
  T b;
};

struct S f(struct S x, struct S y, struct S z, int a)
{
  x.a += y.a + z.a;
  x.b += y.b + z.b + a;
  return x;
}

int main()
{
  return 0;
}
