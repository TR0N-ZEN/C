#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main ()
{
  int a = 32;
  int* c = &a;
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
    *c = 16;
    printf("CHILD: a=%i\n", a);
    sleep(9);
    return 0;
  }
}
