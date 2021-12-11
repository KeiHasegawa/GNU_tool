struct S {
  int i[8];
};

struct S f()
{
  struct S s = { 10, 11, 12, 13, 14, 15, 16, 17};
  return s;
}

int main()
{
  struct S s = f();
  return 0;
}
