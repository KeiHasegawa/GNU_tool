struct S {
  int a;
  int b;
};

int f(struct S s)
{
  return s.a + s.b;
}

int main(void)
{
  return 0;
}
