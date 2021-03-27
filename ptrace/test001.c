#include <sys/ptrace.h>
#include <unistd.h>
#include <signal.h>
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
  int pid = fork();
  if (pid < 0) {
    puts("fork failed");
    print_errno();
    return -1;
  }
  if (pid) {
    // parent process
    if (ptrace(PTRACE_TRACEME, pid) != 0) {
      puts("ptrace(PTRACE_TRACEME) failed");
      print_errno();
    }
    if (kill(pid, SIGKILL) != 0) {
      puts("kill failed");
      print_errno();
    }
  }
  else {
    // child process
    while (1) {
      puts("This message is send by child process");
      sleep(10);
    }
  }
  return 0;
}
