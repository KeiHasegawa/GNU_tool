struct S {
  int a;
  int b;
};

//        r0          r1      r2          r3      r4          r5
int f(int a0, struct S x, int a1, struct S y, int a3, struct S z,
      int a4, struct S u, int a5, struct S v)
{
  return a0 + x.a + x.b + a1 + y.a + y.b + a3 + z.a + z.b
    + a4 + u.a + u.b + a5 + v.a + v.b;
}

int main(void)
{
  return 0;
}
