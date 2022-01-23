int g(int a0, int a1);

void h(char*);


struct S {
  int i[5];
};

struct S f()
{
  struct S s = { 1, 2, 3, 4, 5 };
  return s;
}
