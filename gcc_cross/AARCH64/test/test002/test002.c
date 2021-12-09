struct S {
  char c[128];
};

struct S f()
{
  struct S s = { "hasegawa kei" };
  return s;
}

int main()
{
  struct S s = f();
  return 0;
}
