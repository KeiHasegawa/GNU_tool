long f(int a0, long a1)
{
  return a0 + a1;
}

int main()
{
  return f(32767, 32768L);
}
