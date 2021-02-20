#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a;
    //
    enum Wochentage { Mo, Di, Mi, Do, Fr, Sa, So } Tag1, Tag2;
    //<=>
    //enum Wochentage { Mo, Di, Mi, Do, Fr, Sa, So };
    enum Wochentage Tag3, Tag4;
    //<=>
    //enum { Mo, Di, Mi, Do, Fr, Sa, So } Tag5;
    //enum { Mo, Di, Mi, Do, Fr, Sa, So } Tag6;
    //
    Tag1 = Mo; // is equal to the integer value 0
    Tag2 = Di; // ----------------------------- 1
    Tag3 = Mi; //------------------------------ 2
    Tag4 = Do; //------------------------------ 3
    //Tag5 = Fr; //------------------------------ 4
    //Tag6 = Sa; //------------------------------ 5
    printf("%d\n", So);
    scanf("%d", &a); //a is a variable holding an integer. &a is the memory address of the varible and so the adress of the value it holds
    return 0;
} 
