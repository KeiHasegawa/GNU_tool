struct S {
  int i[4];
};

struct S f()
{
  struct S s = { 1, 2, 3, 4 };
  return s;
}

int main()
{
  struct S s = f();
  return 0;
}
