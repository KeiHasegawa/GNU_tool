void f(const char* s)
{
}

extern void dummy_func();

int main()
{
  f("howdy\n");
  dummy_func();
  return 0;
}
