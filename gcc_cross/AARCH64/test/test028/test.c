typedef long long int T;

struct S {
  T a;
  T b;
  T c;
};

struct S f(int a0, struct S x, int a1, struct S y, int a2)
{
  x.a += a0 + y.a;
  x.b += a1 + y.b;
  x.c += a2 + y.c;
  return x;
}

int main()
{
  return 0;
}
