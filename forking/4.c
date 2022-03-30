#include <sys/types.h>
#include <sys/wait.h>

// pid_t wait(int *x);
// the argument (x) is a pointer to an integer
// returns the pid of the terminated child process and
// saves the exit status (/return value) of the child process in the memory cell that was given as argument to wait

int main()
{
  int pid;
  int rv;
  pid = fork(); // because of fork the execution of the enclosing code block doubles so the code is run once for the parent and once for the child
  if (pid == 0) // child process
  {
    return 13; // exit status from child process is 13
  }
  else // parent process
  {
    wait(&rv); // &rv is a pointer to a memoryaddress where an integer is saved
    printf("In parent process: exit status from child is in decimal %d, in hexadecimal %0x\n", rv, rv);
  }
  return 0;
}