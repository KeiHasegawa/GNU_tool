int f(int a)
{
  if (a) {
    return a - 3;
  }
  return a + 5;
}

int main()
{
  f(1);
  return 0;
}
