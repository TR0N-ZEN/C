#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int a;
    //
    enum Wochentage { Mo, Di, Mi, Do, Fr, Sa, So } Tag1, Tag2;
    //<=>
    enum Wochentage { Mo, Di, Mi, Do, Fr, Sa, So };
    enum Wochentage Tag3, Tag4;
    //<=>
    enum { Mo, Di, Mi, Do, Fr, Sa, So } Tag5;
    enum { Mo, Di, Mi, Do, Fr, Sa, So } Tag6;
    //
    Tag1 = Mo;
    Tag2 = Di;
    Tag3 = Mi;
    Tag4 = Do;
    Tag5 = Fr;
    Tag6 = Sa;
    printf("%d\n", So);
    scanf("%d", &a); //a is a variable holding an integer. &a is the memory address of the varible and so the adress of the value it holds
    return 0;
} 
