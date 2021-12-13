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
  return s.i[0] + s.i[1] + s.i[2] + s.i[3] + s.i[4];
}
