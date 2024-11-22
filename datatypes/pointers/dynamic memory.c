#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int sixPack[6]; // sixPack is now a datatype datatype and defined as an array holding 6 integer values

typedef sixPack* pointer_to_sixPack; // pointer_to_sixPack is now a datatype and defined as a pointer to the first memory cell holding a sixPack

pointer_to_sixPack a; //declared variable a as of type pointer_to_sixPack

void pause()
{
  printf ( "\nPress [Enter] to continue..." );
  //fflush ( stdout );
  //getchar();
  char c1;
  scanf("%c", &c1);
}

int main()
{
  a = (pointer_to_sixPack) malloc(sizeof(sixPack)); // malloc(<int>) reserves the amount of bytes given as int and returns the leading memory address of the reserved memory block, so basically it returns a pointer
  for (int i = 0; i < 10; i++) { (*a)[i] = i+1; }
  for (int i = 0; i < 10; i++) { printf("\n%i", (*a)[i]); }
  pause();
}
