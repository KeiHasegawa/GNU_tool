#include <string.h>
#include <sys/stat.h>

char* sbrk(int incr)
{
  extern char _heap;
  static int delta;
  char* ret =  &_heap + delta;
  delta += incr;
  return ret;
}


int fstat(int fd, struct stat* st)
{
  memset(st, 0, sizeof *st);
  st->st_mode = 0x2190;  
  return 0;
}

int isatty(int fd)
{
  return 1;
}

int write(int fd, const char* buf, int len)
{
  return len;
}

void close()
{
}

void lseek()
{
}

void read()
{
}

