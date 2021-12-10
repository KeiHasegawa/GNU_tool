#include <sys/stat.h>
#include <string.h>

int _fstat(int fd, struct stat* st)
{
  memset(st, 0, sizeof*st);
  st->st_mode = 0x2190;  
  return 0;
}

char* _sbrk(long incr)
{
  extern char heap;
  static long delta;
  char* ret =  &heap + delta;
  delta += incr;
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

void _close()
{
}


void _read()
{
}

void _lseek()
{
}
