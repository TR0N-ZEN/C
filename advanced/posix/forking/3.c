#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// process is a running instance of a program

void exitfunc() {
   printf("\tCalled cleanup function - exitfunc()\n");
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
  char halt[20]; // not shared between processes
  printf("Press any key and enter to continue(1)...\n");
  scanf("%s", halt);
  pid = fork();
  // the following two lines cause strange behaviour because
  //    of inputs and outputs of the two processes attached to the terminal you start the programm from
  // printf("Press any key and enter to continue(2)...\n");
  // scanf("%s", halt); // this seemingly gets executed in the parent process only, maybe
  //    it is executed in the child process but not waiting for input
  if (pid < 0)
  {
    perror("fork() failure\n");
    return 1;
  }
  pidOfThisProcess = getpid();   // getpid() returns the process id of the current process
  ppidOfThisProcess = getppid(); // getppid() returns parent process id of the current process
  if (pid == 0) // pid equals 0 if the process running is the child process so the following block is executed in child processes only
  {
    printf("\tThis is child process\n");
    printf("\tPID is %d and PPID is %d\n", pidOfThisProcess, ppidOfThisProcess);
    printf("\tPress any key and enter to continue(3 - child)...\n\t");
    scanf("%s", halt);
    printf("\thalt in child scanned %s\n", halt);
    // atexit(exitfunc);
    // exit(0); // why not return - because exit(0) triggers exitfunc?
    return 0;
  }
  else  // in parent process only
  {
    sleep(30);
    printf("This is the parent process\n");
    printf("PID is %d and PPID is %d\n", pidOfThisProcess, ppidOfThisProcess);
    // printf("child PID is %d\n", pid);
    printf("Press any key and enter to continue(3 - parent)...\n");
    scanf("%s", halt);
    printf("halt in parent scanned %s\n", halt);
  }
  return 0;
}
