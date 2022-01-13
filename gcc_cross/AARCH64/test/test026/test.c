typedef long long int T;

struct S {
  T a;
  T b;
  T c;
};

T f(struct S s)
{
  return s.a + s.b + s.c;
}

int main()
{
  return 0;
}
