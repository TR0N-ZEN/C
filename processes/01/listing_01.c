#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{
  for(int i=0;i<5;i++)
  {
    if(fork() == 0)
    // the following block is only executed by child process
    {
      printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
      sleep(30);

      // to stop the process from further execution of the enclosing
      // loop it so the process exits/terminates
      exit(0);
    }
  }
  // From here a(n arc) parent process would be able to
  // orchestrate locks of processes I think.
  wait(NULL);
}
