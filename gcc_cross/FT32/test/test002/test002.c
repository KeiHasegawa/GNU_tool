void* a[3] = { (void*)0x800000, (void*)0x800000, &a[2] };

void f(void* p)
{
}

int main()
{
  f(a[2]);
  return 0;
}
