int f(int a, int b)
{
  switch (b) {
  case 0: return (a >> 0) & 0xff;
  case 1: return (a >> 8) & 0xff;
  case 2: return (a >> 16) & 0xff;
  case 3: return (a >> 24) & 0xff;
  default: return a;
  }
}

int main()
{
  f(3, 7);
  return 0;
}
