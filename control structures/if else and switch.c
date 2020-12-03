#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("Enter one integer from 1 to 6: ");
    int x;
    scanf("%i",&x);
    printf("\n");
    
    if(x == 1){
        printf("You typed %i.\n",x);
    }else{
        printf("Apparrently not 1.\n(You typed %i instead).\n",x);
    }
    printf("\n");
    
    switch(x){
        case 1: printf("You typed 1\n"); break;
        case 2: printf("You typed 2\n"); break;
        case 3: printf("You typed 3\n"); break;
        case 4: printf("You typed 4\n"); break;
        case 5: printf("You typed 5\n"); break;
        case 6: printf("You typed 6\n"); break;
        default: printf("Man you typed shit!\n");
    }
} 
