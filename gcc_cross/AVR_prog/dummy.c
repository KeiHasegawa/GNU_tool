#include <reent.h>
#include <stdio.h>

unsigned char my_buffer[128];

int __swsetup_r(struct _reent *ptr, FILE* fp)
{
  if (!fp->_p)
    fp->_p = &my_buffer[0];
  return 0;
}

int _close_r(struct _reent * ptr, int fd)
{
  return 0;
}

_off_t _lseek_r(struct _reent * ptr, int fd, _off_t offset, int x)
{
  return offset;
}

void _malloc_r()
{
}

void _free_r()
{
}

_ssize_t _read_r(struct _reent* ptr, int fd, void* buf, size_t size)
{
  return size;
}

void _write()
{
}
