extern int var;

int* f0()
{
  return &var;
}

int* f1()
{
  return &var;
}

int* f2()
{
  return &var;
}

int* f3()
{
  return &var;
}

int main()
{
  f0();
  f1();
  f2();
  f3();
  return 0;
}
