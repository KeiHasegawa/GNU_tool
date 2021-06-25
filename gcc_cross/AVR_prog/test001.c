int f(const char* p)
{
  int ret = 0;
  while (*p++)
    ++ret;
  return ret;
}


int main()
{
  return f("hello world\n");
}
