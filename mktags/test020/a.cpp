template<class C1, class C2>
class basic_ostream {
};

template<typename _Traits>
inline basic_ostream<char, _Traits>&
operator<<(basic_ostream<char, _Traits>& __out, const char* __s)
{
  return __out;
}

int main()
{
  basic_ostream<char, int> bo;
  bo << "hello";
  return 0;
}
