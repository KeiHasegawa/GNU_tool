#include <sys/stat.h>
#include <string.h>

int _fstat(int fd, struct stat* st)
{
  memset(st, 0, sizeof*st);
  st->st_mode = 0x2190;
  return 0;
}

char* _malloc_r(int size)
{
  extern char heap;
  static int delta;
  char* ret = &heap + delta;
  delta += size;
  return ret;
}

void _free_r(void* ptr)
{
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
