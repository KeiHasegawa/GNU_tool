int abc = 123;

int def;

int f(const char* s)
{
  int n = 0;
  while (*s++)
    ++n;
  return n;
}

void g(int a, int b, int c)
{
}

int main()
{
  int a = f("hello world");
  def = 456;
  g(a, abc, def);
  return 0;
}
