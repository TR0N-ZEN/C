#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

// process is a running instance of a program

void exitfunc() {
   printf("Called cleanup function - exitfunc()\n");
   return;
}

int main ()
{
  pid_t pid, pidOfThisProcess, ppidOfThisProcess;
  pid = getpid();
  printf("This ist the parent process before calling fork() the process id is %d\n", pid);
  // fork() executed in the parent process returns the PID of the child process, 
  // fork() executed in the child process returns 0
  // fork() returns a negative integer if an error occured
  char halt[20];
  scanf("%s", halt); // this seemingly gets executed in the parent process only
  pid = fork();
  if (pid < 0)
  {
    perror("fork() failure\n");
    return 1;
  }
  pidOfThisProcess = getpid();   // getpid() returns the process id of the current process
  ppidOfThisProcess = getppid(); // getppid() returns parent process id of the current process
  printf("Process id is %d and PPID is %d\n", pidOfThisProcess, ppidOfThisProcess);
  if (pid == 0) // pid equals 0 if the process running is the child process so the following block is executed in child processes only
  {
    printf("This is child process\n");
    atexit(exitfunc);
    exit(0); // why not return - because exit(0) triggers exitfunc?
  }
  else  // in parent process only
  {
    printf("This is the parent process\n");
    printf("\tchild PID is %d\n", pid);
    scanf("%s", halt);
  }
  return 0;
}