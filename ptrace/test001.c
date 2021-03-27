#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

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

void print_status(int status)
{
  printf("status = %d\n", status);
  if (WIFEXITED(status))
    printf("exit %d\n", WEXITSTATUS(status));
  if (WIFSIGNALED(status))
    printf("signaled with signal no %d\n", WTERMSIG(status));
  if (WIFSTOPPED(status))
    printf("stopped with signal no %d\n", WSTOPSIG(status));
  if (WIFCONTINUED(status))
    puts("continued");
}

void print_regs(struct user_regs_struct* regs)
{
  printf("eax = 0x%x ebx = 0x%x\n", regs->eax, regs->ebx);
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
  int status;
  if (wait(&status) < 0) {
    printf("wait() failed");
    print_errno();
    return 3;
  }
  print_status(status);
  struct user_regs_struct regs;
  if (ptrace(PTRACE_GETREGS, pid, 0, &regs) < 0) {
    printf("ptrace(PTRACE_GETREGS, %d) failed\n", pid);
    print_errno();
    return 4; 
  }
  print_regs(&regs);
  if (ptrace(PTRACE_CONT, pid, 0, SIGCONT) < 0) {
    printf("ptrace(PTRACE_CONT, %d, 0, SIGCONT) failed\n", pid);
    print_errno();
    return 5; 
  }
  return 0;
}
