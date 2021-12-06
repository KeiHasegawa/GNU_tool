namespace std {
  void __throw_length_error(const char*)
  {
    asm("sleep");
  }
  void __throw_bad_alloc()
  {
    asm("sleep");
  }
}

void operator delete(void*, unsigned int)
{
}

void* operator new(unsigned int sz)
{
  static auto p = reinterpret_cast<char*>(0x5000);
  auto ret = reinterpret_cast<void*>(p);
  p += sz;
  return ret;
}

extern "C" void* memmove(void* dst, const void* src, unsigned int n)
{
  auto d = reinterpret_cast<char*>(dst);
  auto s = reinterpret_cast<const char*>(src);
  while (n--)
    *d++ = *s++;
  return dst;
}
