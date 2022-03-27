#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

// process is a running instance of a program

void exitfunc() {
   printf("Called cleanup function - exitfunc()\n");
   return;
}

int main()
{
   pid_t pid, pidOfThisProcess, ppidOfThisProcess;
   pid = getpid();
   printf("Before possible fork: Process id is %d\n", pid);
   // fork() executed in the parent process returns the PID of the child process, 
   // fork() executed in the child process returns 0
   // fork() returns a negative integer if an error occured
   pid = fork();

   if (pid < 0)
   {
      perror("fork() failure\n");
      return 1;
   }

   if (pid == 0) // pid equals 0 if the process running is the child process
   {
      printf("This is child process\n");
      pidOfThisProcess = getpid();   // getpid() returns the process id of the current process
      ppidOfThisProcess = getppid(); // getppid() returns parent process id of the current process
      printf("Process id is %d and PPID is %d\n", pidOfThisProcess, ppidOfThisProcess);
      atexit(exitfunc);
      exit(0);
   }
   else  // parent process
   {
      sleep(2);
      printf("This is the parent process\n");
      pidOfThisProcess = getpid();
      ppidOfThisProcess = getppid();
      printf("Process id is %d and PPID is %d\n", pidOfThisProcess, ppidOfThisProcess);
      printf("Newly created process id or child PID is %d\n", pid);
   }
   return 0;
}