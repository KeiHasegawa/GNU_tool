int f(const char* p)
{
  int ret = 0;
  while (*p++)
    ++ret;
  return ret;
}

int main()
{
  f("hello world");
  return 0;
}
