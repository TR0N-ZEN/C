#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("\n");
    
    for (int x=5;x>0,--x;){
        printf("%i",x);
    };
    printf("\n");
    
    for (int x=5;x>0,x--;){
        printf("%i",x);
    };
    printf("\n");
    
    int x = 5;
    while(x>0){
        printf("%i",x);
        x--;
    }
    printf("\n");
    
    x = 5;
    while(x>0){
        printf("%i",x);
        --x;
    }
    printf("\n");
    
    x = 5;
    do {
        printf("%i", x);
        --x;
    } while (x>0);
    printf("\n");
    
    x = 5;
    do {
        printf("%i", x);
        x--;
    } while (x>0);
    printf("\n");
    
    return 0;
 }
