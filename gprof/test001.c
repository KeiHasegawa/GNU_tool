void f(int n)
{
  while (--n)
    ;
}

int main()
{
  f(0x4000);
  return 0;
}
