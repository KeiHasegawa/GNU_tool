#include <setjmp.h>
#include <stdio.h>

void f(jmp_buf env)
{
  longjmp(env, 123);
}

void g()
{
}

int main()
{
  jmp_buf env;
  int n = setjmp(env);
  if (n == 0) {
    f(env);
    g();
  }
  else {
    printf("setjmp returned %d\n", n);
  }
  return 0;
}
