template<class C> struct S {};

extern template class S<int>;

int main()
{
  return 0;
}
