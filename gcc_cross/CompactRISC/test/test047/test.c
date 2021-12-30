struct S {
  int a;
  int b;
  int c;
};

int f(struct S s)
{
  return s.a + s.b + s.c;
}

struct T {
  struct S s;
  int x;
  int y;
  int z;
};

int g(struct T t)
{
  return f(t.s) + t.x + t.y + t.z;
}

int main()
{
  return 0;
}
