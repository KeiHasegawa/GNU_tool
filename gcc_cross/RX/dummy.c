#include <sys/stat.h>
#include <string.h>

int fstat(int fd, struct stat* st)
{
  memset(st, 0, sizeof*st);
  st->st_mode = 0x2190;  
  return 0;
}

char* sbrk(long incr)
{
  extern char end;
  static long delta;
  char* ret =  &end + delta;
  delta += incr;
  return ret;
}

int isatty(int fd)
{
  return 1;
}

int write(int fd, const char* buf, int len)
{
  return len;
}

void close(){}
void lseek(){}
void read(){}
