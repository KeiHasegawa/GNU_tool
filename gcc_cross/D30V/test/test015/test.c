struct S {
  int i[16];
};

struct S f(struct S a, struct S b, struct S c)
{
  int N = sizeof a.i/sizeof a.i[0];
  for (int i = 0 ; i != N ; ++i)
    a.i[i] += b.i[i] + c.i[i];
  return a;
}

int main()
{
  return 0;
}
