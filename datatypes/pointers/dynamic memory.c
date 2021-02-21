#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef int feld[10];

typedef feld* pointer_to_feld; // pointer_to_feld is a pointer to the first memory cell holding a feld

pointer_to_feld a;

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
    a = (pointer_to_feld) malloc(sizeof(feld));
    for (int i = 0; i < 10; i++) { (*a)[i] = i+1; }
    for (int i = 0; i < 10; i++) { printf("\n%i", (*a)[i]); }
    pause();
}