int _isatty(int fd)
{
  return 1;
}

int _write(int fd, const char* buf, int len)
{
  return len;
}
