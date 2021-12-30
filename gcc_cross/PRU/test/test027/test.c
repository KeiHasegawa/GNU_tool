typedef long long int T;

T f(int a0, T a1, int a2, int a3, T a4, int a5, int a6, int a7,
    int b0, int b1, T b2, int b3, T b4, int b5, int b6, int b7,
    T c0, int c1)
{
  return a0 + a1 + a2 + a3 + a4 + a5 + a6 + a7 +
    b0 + b1 + b2 + b3 + b4 + b5 + b6 + b7 +
    c0 + c1;
}

int main()
{
  f(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18);
  return 0;
}
