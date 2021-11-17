#include <sys/stat.h>
#include <string.h>

void* _sbrk(int inc)
{
  extern char end;
  static int delta = 0;
  void* ret = &end+delta;
  delta += inc;
  return ret;
}

int _fstat(int fildes, struct stat *st)
{
  memset(st, 0, sizeof*st);
  st->st_mode = 0x2190;
  return 0;
}

int _isatty(int fd)
{
  return 1;
}

int _write(int fd, const char* buf, int len)
{
  return len;
}

void _close()
{
}

void _lseek()
{
}

void _read()
{
}
