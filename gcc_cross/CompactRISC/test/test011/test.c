extern int _isatty(int);
extern int _write(int fd, const char* buf, int len);

int main()
{
  _isatty(1);
  _write(1, "hello world\n", 12);
  _isatty(1);
  _write(1, "hello world\n", 12);
  _isatty(1);
  _write(1, "hello world\n", 12);
  _isatty(1);
  _write(1, "hello world\n", 12);
  return 0;
}
