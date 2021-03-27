#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
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
  printf("eip = 0x%x\n", regs->eip);
}

int main()
{
  int pid = fork();
  if (pid < 0) {
    puts("fork failed");
    print_errno();
    return 1;
  }
  if (pid) {  // parent process
    int status;
    if (wait(&status) < 0) {
      printf("wait(&status) failed\n", pid);
      print_errno();
      return 2;
    }
    print_status(status);
    if (ptrace(PTRACE_CONT, pid, 0, SIGCONT) < 0) {
      printf("ptrace(PTRACE_CONT, %d, 0, SIGCONT) failed\n", pid);
      print_errno();
      return 3; 
    }
    if (wait(&status) < 0) {
      printf("wait(&status) failed\n", pid);
      print_errno();
      return 4;
    }
    print_status(status);
    struct user_regs_struct regs;
    if (ptrace(PTRACE_GETREGS, pid, 0, &regs) < 0) {
      printf("ptrace(PTRACE_GETREGS, %d) failed\n", pid);
      print_errno();
      return 5;
    }
    print_regs(&regs);
    if (ptrace(PTRACE_CONT, pid, 0, SIGCONT) < 0) {
      printf("ptrace(PTRACE_CONT, %d, 0, SIGCONT) failed\n", pid);
      print_errno();
      return 6; 
    }
  }
  else {  // child process
    printf("%s:%d\n", __FILE__, __LINE__);
    if (ptrace(PTRACE_TRACEME) < 0) {
      puts("ptrace(PTRACE_TRACEME) failed");
      return 7;
    }
    if (execl("./test005.exe", "./test005.exe", 0)) {
      printf("execl() returned\n");
      print_errno();
      return 8;
    }
  }
  return 0;
}
