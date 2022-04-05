#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int x = 5;
  //first checked if it can be run and then executed if if it can be run
  while( x > 0 )
  {
    printf("%i",x);
    x--;
  };
  
  x = 5;
  //first checked if it can be run and then executed if if it can be run
  while( x > 0 )
  {
    printf("%i",x);
    --x;
  };
  
  return 0;
 }
