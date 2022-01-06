int printf(const char* fmt, ...);

void f(float a)
{
  printf("%f\n", a);
}

int main()
{
  f(2.0);
  return 0;
}
