template<class C1> struct S1 {};

template<class C2> struct S2 {};

int main()
{
  S1<int>* p = nullptr;
  S2<int> si;
  return 0;
}
