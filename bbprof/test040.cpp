int a;

struct B {
  B(){}
  B(const B&){}
};

void f(B b)
{
}

struct B b;

int main()
{
  if (a)
    f(b);
  return 0;
}
