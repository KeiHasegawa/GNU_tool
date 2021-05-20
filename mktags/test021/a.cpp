namespace std __attribute__ ((__visibility__ ("default")))
{
  template<class _CharT>
    struct char_traits;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ostream;
}

namespace mine {
  template<class C> struct S;
}

struct X;

int main()
{
  using namespace std;
  basic_ostream<char> *p = nullptr;

  using namespace mine;
  S<int>* q = nullptr;

  X* r = nullptr;
  return 0;
}
