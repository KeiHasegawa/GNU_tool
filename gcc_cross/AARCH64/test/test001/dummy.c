#include <string.h>
#include <sys/stat.h>

void _close(){}
void _lseek(){}
void _read(){}

int _fstat(int fildes, struct stat *st)
{
  memset(st, 0, sizeof*st);
  st->st_mode = 0x2190;
  return 0;
}

void* _sbrk(long inc)
{
  extern char end;
  static long delta = 0;
  void* ret = &end+delta;
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

size_t strlen(const char* s)
{
  size_t len = 0;
  while (*s++)
    ++len;
  return len;
}
