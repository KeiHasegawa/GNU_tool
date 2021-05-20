struct S {
  int m;
};

inline S& operator<<(S& s, int n)
{
  s.m = n;
  return s;
}

int main()
{
  S s;
  s << 10;
  return 0;
}
