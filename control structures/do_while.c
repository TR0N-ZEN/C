#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int x = 5;
  //will be run once in any case and then checked if it can be run again
  do
  {
    printf("%i", x);
    --x;
  }
  while ( x > 0 );
  
  x = 5;
  //will be run once in any case and then checked if it can be run again
  do
  {
    printf("%i", x);
    x--;
  }
  while ( x > 0 );
  
  return 0;
 }
