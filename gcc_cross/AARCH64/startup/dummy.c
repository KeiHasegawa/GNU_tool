#include <string.h>
#include <sys/stat.h>

void _exit(int status){}
void _close(){}
void _lseek(){}
void _read(){}

int _fstat(int fildes, struct stat *st)
{
  st->st_dev = 0;
  st->st_ino = 0;
  st->st_mode = 0x2190;
  st->st_nlink = 0;
  st->st_uid = 0;
  st->st_gid = 0;
  st->st_rdev = 0;
  st->st_size = 0;
  st->st_atim.tv_sec = 0;
  st->st_atim.tv_nsec = 0;
  st->st_ctim.tv_sec = 0;
  st->st_ctim.tv_nsec = 0;
  st->st_blksize = 0;
  st->st_blocks = 0;
  st->st_spare4[0] = 0;
  st->st_spare4[1] = 0;
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
