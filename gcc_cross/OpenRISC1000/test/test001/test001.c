struct S {
  int i[6];
};

struct S f()
{
  struct S s = { 1, 2, 3, 4, 5, 6};
  return s;
}

int main()
{
  struct S s = f();
  return s.i[0] + s.i[1] + s.i[2] + s.i[3] + s.i[4] + s.i[5];
}
