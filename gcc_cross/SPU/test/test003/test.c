#define vec_int4                __vector   signed int

vec_int4 f(vec_int4 a, vec_int4 b)
{
  return a + b;
}

int main()
{
  f((vec_int4){1, 2, 3, 4}, (vec_int4){5, 6, 7, 8});
  return 0;
}
