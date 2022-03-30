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
  int process_maximum = 4;
  int process_ids[process_maximum];
  while (process_counter < process_maximum)
  {
    int pid = fork(); // from here again the execution doubles for then enclosing blockstatement so here each interation in the while loop
    if (pid != 0) // not the child process <=> parent process;
    {
      printf("In parent: PID of the just created child process is: %s.", pid);
      pids[process_counter++] = pid;
    }
    else // child process
    {
      printf("The PID of this child process: %s", getpid());
    }
    process_counter++;
  }
  waitpid(pids[process_maximum - 1], &rv, 0);
  if (WIFEXITED(rv) != 0) // wifexited - short for 'worker if exited'
  {
    printf("process %d exited normally\n", pids[process_maximum - 1]);
    printf("exited status from child is %d\n", WIFEXITSTATUS(rv));
  }
  else
  {
    printf("process with PID %d terminated abnormally.", pids[process_maximum - 1]);
  }
}

