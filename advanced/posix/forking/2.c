#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
  char halt[20];
  int x;
  printf("Press any key and enter to continue(1)...\n");
  scanf("%s", halt); // this line is to pause the process by waiting for input
  // sleep(10);
  x = fork(); 
  // fork() doubles the execution of the enclosing code block (code blocks are sourrounded by {} (curly braces))
  //    once executed in the parent process and once in the child process
  // fork() executed inside the parent process returns the PID of the child process, 
  // fork() executed inside the child process returns 0
  // fork() returns a negative integer if an error occured
  printf("fork() returns %d\n", x);
  // sleep(10);
  printf("Press any key and enter continue(2)...\n");
  scanf("%s", halt); // this line is to pause the process by waiting for input
  return 0;
}
