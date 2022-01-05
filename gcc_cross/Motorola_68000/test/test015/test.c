int printf(const char* fmt, ...);

void f(int a, int b)
{
  printf("%d + %d = %d\n", a, b, a+b);
}

int main()
{
  printf("hasegawa");
  printf("\n");
  return 0;
}
