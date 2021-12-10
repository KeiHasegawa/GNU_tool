struct S {
  int i[6];
};

struct S f()
{
  struct S s = {
    1111, 2222, 3333, 4444, 5555, 6666
  };
  return s;
}

void g(struct S s)
{
}

int main()
{
  struct S s = f();
  g(s);
  return 0;
}
