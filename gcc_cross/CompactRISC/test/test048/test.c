struct S {
  int a;
  int b;
  int c;
};

int f(struct S s, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  return s.a + s.b + s.c + a1 + a2 + a3 + a4 + a5 + a6 + a7;
}

int main()
{
  return 0;
}
