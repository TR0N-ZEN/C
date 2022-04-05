#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main ()
{
  int a = 32;
  int b;
  b = fork();
  if (b != 0)
  {
    printf("PARENT: a=%i\n", a);
    sleep(9);
    printf("PARENT: a=%i\n", a);
    sleep(6);
    return 0;
  }
  else
  {
    sleep(3);
    printf("CHILD: a=%i\n", a);
    a = 16;
    printf("CHILD: a=%i\n", a);
    sleep(9);
    return 0;
  }
}

// resumee: a CHILD can use variables from the PARENT and change them in their own scope but can't change the value in the scope of the PARENT

