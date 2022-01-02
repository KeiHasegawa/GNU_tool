typedef long long int T;

struct S {
  T a;
  T b;
};

struct S f(int a0, struct S s, int a1)
{
  s.a += a0;
  s.b += a1;
  return s;
}

int main()
{
  return 0;
}
