struct S {
  int i[9];
};

struct S f()
{
  struct S s = { 11, 12, 13, 14, 15, 16, 17, 18, 19 };
  return s;
}

int main()
{
  struct S s = f();
  return 0;
}
