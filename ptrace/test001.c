#include <sys/ptrace.h>
#include <sys/user.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char** argv)
{
  if (argc != 2) {
    printf("usage % %s pid\n", argv[0]);
    return 1;
  }
  int pid = atoi(argv[1]);
  if (ptrace(PTRACE_ATTACH, pid) < 0) {
    printf("ptrace(PTRACE_ATTACH, %d) failed\n", pid);
    print_errno();
    return 2;
  }
  struct user_regs_struct regs;
  if (ptrace(PTRACE_GETREGS, pid, 0, &regs) < 0) {
    printf("ptrace(PTRACE_GETREGS, %d) failed\n", pid);
    print_errno();
    return 3; 
  }
  return 0;
}
