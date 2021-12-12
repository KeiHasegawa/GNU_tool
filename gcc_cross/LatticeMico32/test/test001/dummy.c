#include <sys/stat.h>
#include <string.h>

int _fstat(int fd, struct stat* st)
{
  memset(st, 0, sizeof*st);
  st->st_mode = 0x2190;
  return 0;
}

char* _sbrk(int size)
{
  extern char _heap;
  static int delta = 0;
  char* ret = &_heap+delta;
  delta += size;
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

