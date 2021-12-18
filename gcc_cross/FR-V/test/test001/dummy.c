
#include <string.h>
#include <sys/stat.h>

int _fstat(int fildes, struct stat *st)
{
  memset(st, 0, sizeof*st);
  st->st_mode = 0x2190;
  return 0;
}

void* _sbrk(long inc)
{
  extern char _heap;
  static long delta = 0;
#if 0
  void* ret = &_heap + delta;
#else
  void* ret = (void*)0x6000+delta;
#endif  
  delta += inc;
  return ret;
}

int _isatty(int fd)
{
  return 1;
}

int _write(int fd, const char* buf, int len)
{
  return len;
}

void _close(){}
void _lseek(){}
void _read(){}
