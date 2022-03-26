#include <sys/types.h>
#include <sys/wait.h>

// pid_t wait(int *x);
// the argument (x) is a pointer to an integer
// returns the pid of the terminated child process and
// saves the exit status (/return value) of the child process in the memory cell that was given as argument to wait

int main() {
   int pid;
   int status;
   pid = fork();
   
   
   if (pid == 0) // child process
   {
      //system("ps -ef");
      sleep(10);
      //system("ps -ef");
      return 13; // exit status from child process is 13
   }
   else // parent process
   {
      sleep(3);
      wait(&status);
      printf("In parent process: exit status from child is decimal %d, hexa %0x\n", status, status);
   }
   return 0;
}