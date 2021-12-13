struct S {
  int i[17];
};

struct S f()
{
  struct S s = {
    10, 11, 12, 13, 14, 15, 16, 17,
    18, 19, 20, 21, 22, 23, 24, 25,
    26 };
  return s;
}

int main()
{
  struct S s = f();
  return 0;
}
