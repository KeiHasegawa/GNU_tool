struct S {
  int i[3];
};

struct S f(int a)
{
  struct S s = { 1, 2, a };
  return s;
}

int main()
{
  struct S s = f(3);
  return 0;
}
