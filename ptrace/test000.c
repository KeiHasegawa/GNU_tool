#include <sys/ptrace.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

void print_errno(void)
{
  switch (errno) {
  case EBUSY:
    puts("EBUSY");
    return;
  case EFAULT:
    puts("EFAULT");
    return;
  case EINVAL:
    puts("EINVAL");
    return;
  case EIO:
    puts("EIO");
    return;
  case EPERM:
    puts("EPERM");
    return;
  case ESRCH:
    puts("ESRCH");
    return;
  default:
    printf("errno = %d\n", errno);
    return;
  }
}

int main()
{
  int pid = getpid();
  int ret = ptrace(PTRACE_TRACEME, pid);
  printf("ret = %d\n", ret);
  if (ret != 0)
    print_errno();
  return 0;
}
