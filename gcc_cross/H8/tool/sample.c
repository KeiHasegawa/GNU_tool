int printf(const char*, ...);

int main()
{
  long double ld = 1.2L;
  printf("%Lf\n", ld);
  return 0;
}
