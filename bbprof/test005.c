int f(int a, int b, int c)
{
  return a ? b + c : b - c;
}

int main()
{
  return f(3, 4, 5);
}
