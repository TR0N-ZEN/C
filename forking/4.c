#include <sys/types.h>
#include <sys/wait.h>

// pid_t waitpid(pid_t x, int *y, int z);
// first argument (x) is the pid of the child process the parent process waits for to terminate
//   if x < (-1) then the parent process proceeds when a process of the group id |x| terminates
//   if x = (-1) then the parent process proceeds when any of the child_processes terminates
//   if x = 0    then the parent process proceeds when a process of the same group id as the parent process terminates
//   if x > 0    then the parent process proceeds when a process of the pid x terminates
// second argument (y) is a pointer to an integer, which is the memory address 
//     where the exit status (/ return value) of the child process will be saved
// third argument I don't know yet

