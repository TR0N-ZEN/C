#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float x,y,z;
 
float function1(float x,float y);
 
int main(){
    scanf("%f",&x);
    scanf("%f",&y);
    z = function1(x,y);
    printf("%f",z);
    return 0;
 }

float function1(float(x),float(y)){
     return x*y;
 };
