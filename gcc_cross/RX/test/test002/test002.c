struct S {
  int i[5];
};

struct S f();

int main()
{
  struct S s = f();
  return s.i[0] + s.i[1] + s.i[2] + s.i[3] + s.i[4];
}


extern int stack;

int* g()
{
  return &stack;
}

       
void h(char* a)
{
}

