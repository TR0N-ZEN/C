#include <stdio.h>
#include <string.h>

int main ()
{
  char as[30]; // as is an array of ten characters
  printf("Hello there.\n"); // write to the standard-output of the process
  scanf("%s", as); // read from the standard-input of the process
  printf("%s\n", as); // write the content of the variable to the standard-output of the process
  return 0;
}

// if you typed a string containing whitespace(s) then only the first word will be caught by scanf

