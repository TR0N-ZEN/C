#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


// pid_t waitpid(pid_t x, int *y, int z);
// first argument (x) is the pid of the child process the parent process waits for to terminate
//  if x < (-1) then the parent process proceeds when a process of the group id |x| terminates
//  if x = (-1) then the parent process proceeds when any of the child_processes terminates
//  if x = 0    then the parent process proceeds when a process of the same group id as the parent process terminates
//  if x > 0    then the parent process proceeds when a process of the pid x terminates
// second argument (y) is a pointer to an integer, which is the memory address
//     where the exit status (/ return value) of the child process will be saved
// third argument I don't know yet

int main ()
{
  int a,b,rv;
  int process_counter = 0;
  int process_maximum = 10;
  int process_ids[process_maximum];
  while (process_counter < process_maximum)
  {
    int pid = fork(); // from here again the execution doubles for then enclosing
                      // blockstatement so here each interation in the while loop
    if (pid != 0) // check if it is not the child process a.k.a.
                  // check if it is the parent process;
    {
      printf("PARENT: child PID is %i.\n", pid);
      process_ids[process_counter++] = pid;
    }
    else // child process
    {
      int c = process_counter*4 + 5; // since this approach causes the child processes
                                     // to exit with about 4 seconds time delta it
                                     // seems that the enclosing codeblock is ran in
                                     // turns between the parent process and a child
                                     // process;
                                     // 6.c, 7.c, 8.c, 9.c together suggest that
                                     // the child process may get a copy of each variable
                                     // of the parent at time of creation of the child process
      sleep(c);
      printf("\tA CHILD: my PID is %i.\n", getpid());
      return c;
    }
  }
   waitpid(process_ids[process_maximum - 1], &rv, 0);
  if (WIFEXITED(rv) != 0) // wexited - short for 'worker if exited'
  {
    printf("PARENT: %i exited normally.\n", process_ids[process_maximum - 1]);
    printf("PARENT: exit status is %i.\n", WEXITSTATUS(rv)); // wexitstatus - short for 'worker exit status'
  }
  else
  {
    printf("PARENT: %i termienated abnormally.\n", process_ids[process_maximum - 1]);
  }
  return 0;
}

