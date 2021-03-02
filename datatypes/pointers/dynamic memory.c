#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef int feld[10]; // feld is now a datatype datatype and defined as an array holding 10 integer values

typedef feld* pointer_to_feld; // pointer_to_feld is now a datatype and defined as a pointer to the first memory cell holding a feld

pointer_to_feld a; //declared variable a as of type pointer_to_feld

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
    a = (pointer_to_feld) malloc(sizeof(feld)); // malloc(<int>) reserves the amount of bits/bites (not sure but i think bytes) given as int and returns the leading memory address of the reserved memory block, so basically a pointer
    for (int i = 0; i < 10; i++) { (*a)[i] = i+1; }
    for (int i = 0; i < 10; i++) { printf("\n%i", (*a)[i]); }
    pause();
}