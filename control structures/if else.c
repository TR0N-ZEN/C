#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  printf("Enter one integer from 1 to 6: ");
  int x;
  scanf("%i",&x);
  printf("\n");
  
  if(x == 1)
  {
    printf("You typed %i.\n",x);
  }
  else
  {
    printf("Apparrently not 1.\n(You typed %i instead).\n",x);
  }
  printf("\n");
} 
