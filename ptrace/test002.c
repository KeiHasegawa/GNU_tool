#include <unistd.h>
#include <sys/ptrace.h>
#include <errno.h>
#include <stdio.h>

void print_errno(void)
{
  switch (errno) {
  case EBUSY:  puts("EBUSY");  return;
  case EFAULT: puts("EFAULT"); return;
  case EINVAL: puts("EINVAL"); return;
  case EIO:    puts("EIO");    return;
  case EPERM:  puts("EPERM");  return;
  case ESRCH:  puts("ESRCH");  return;
  default:
    printf("errno = %d\n", errno);
    return;
  }
}

int main()
{
  int pid = getpid();
  if (ptrace(PTRACE_ATTACH, pid) < 0) {
    printf("ptrace(PTRACE_ATTACH, %d) failed\n", pid);
    print_errno();
    return 2;
  }
  return 0;
}
