int printf(const char* fmt, ...)
{
  return 0;
}

void f(int a, int b)
{
  printf("%d + %d = %d\n", a, b, a+b);
}

int main()
{
  f(5, 6);
  return 0;
}
