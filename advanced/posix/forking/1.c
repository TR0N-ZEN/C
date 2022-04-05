#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
  char halt[20];
  printf("Before calling fork() system call\n");
  scanf("%s", halt); // this line is to pause the process by waiting for input
  //sleep(10);
  fork();
  // fork() doubles the execution of the enclosing code block (code blocks are sourrounded by {} (curly braces)) from the line where fork() was called until the end of the block
  //    once executed in the parent process and once in the child process, these processes run independent from each other, none waits for the other in an way
  // fork() executed inside the parent process returns the PID of the child process, 
  // fork() executed inside the child process returns 0
  // fork() returns a negative integer if an error occured
  printf("After calling fork() system call\n");
  //sleep(10);
  scanf("%s", halt); // this line is to pause the process by waiting for input
  return 0;
}