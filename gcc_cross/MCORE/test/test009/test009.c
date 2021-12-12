struct S {
  int i[8];
};

struct S f()
{
  struct S s = { 1, 2, 3, 4, 5, 6, 7, 8 };
  return s;
}

int main()
{
  struct S s = f();
  return s.i[5];
}
