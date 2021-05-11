int a;

void f()
{
}

struct S {
  S(){}
};

int main()
{
  if (a)
    f();
  S s = S();
  return 0;
}

