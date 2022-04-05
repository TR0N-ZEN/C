#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int i = 5;
  for (int x = 5; x > 0; --x)
  {
    printf("%i",x);
  };
  
  for (int x = 5; x > 0; x--)
  {
    printf("%i",x);
  };
  
  return 0;
 }
