struct S {
  int i[5];
};


struct S f()
{
  struct S s = { 1, 2, 3, 4, 5 };
  return s;
}

int main()
{
  struct S x = f();
  return 0;
}
