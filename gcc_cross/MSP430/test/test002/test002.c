struct S {
  int i[5];
};

struct S f()
{
  struct S s = { 10, 11, 12, 13, 14 };
  return s;
}

int main()
{
  struct S s = f();
  return 0;
}
