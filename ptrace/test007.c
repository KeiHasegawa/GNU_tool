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
    // set DR_CONTROL (DR7)
    if (ptrace(PTRACE_POKEUSER, pid, 0x118, 0x0) < 0) {
      printf("ptrace(PTRACE_POKEDATA, %d, 0x118, 0x0) failed\n", pid);
      print_errno();
      return 3;
    }
    int addr = 0x804a6a0;
    if (ptrace(PTRACE_POKEUSER, pid, 0xfc, addr) < 0) {  // DR0
      printf("ptrace(PTRACE_POKEDATA, %d, 0xfc, 0x%x) failed\n", pid, addr);
      print_errno();
      return 3;
    }
    // set DR_CONTROL(DR7)
    if (ptrace(PTRACE_POKEUSER, pid, 0x118, 0xd0101) < 0) {
      printf("ptrace(PTRACE_POKEDATA, %d, 0x118, 0xd0101) failed\n", pid);
      print_errno();
      return 3;
    }
    // set DR_STATUS(DR6)
    if (ptrace(PTRACE_POKEUSER, pid, 0x114, 0x0) < 0) {
      printf("ptrace(PTRACE_POKEDATA, %d, 0x114, 0x0) failed\n", pid);
      print_errno();
      return 3;
    }
    if (ptrace(PTRACE_CONT, pid, 0, SIGCONT) < 0) {
      printf("ptrace(PTRACE_CONT, %d, 0, SIGCONT) failed\n", pid);
      print_errno();
      return 4; 
    }
    if (wait(&status) < 0) {
      printf("wait(&status) failed\n", pid);
      print_errno();
      return 5;
    }
    print_status(status);
    for (int i = -5 ; i != +5 ; ++i) {
      int a = addr+4*i;
      errno = 0;
      int data = ptrace(PTRACE_PEEKDATA, pid, a);
      if (errno)
	print_errno();
      printf("0x%x : %d\n", a, data);
    }
    if (ptrace(PTRACE_CONT, pid, 0, SIGCONT) < 0) {
      printf("ptrace(PTRACE_CONT, %d, 0, SIGCONT) failed\n", pid);
      print_errno();
      return 4; 
    }
  }
  else {  // child process
    printf("%s:%d\n", __FILE__, __LINE__);
    if (ptrace(PTRACE_TRACEME) < 0) {
      puts("ptrace(PTRACE_TRACEME) failed");
      return 6;
    }
    if (execl("./test003.exe", "./test003.exe", 0)) {
      printf("execl() returned\n");
      print_errno();
      return 7;
    }
  }
  return 0;
}
