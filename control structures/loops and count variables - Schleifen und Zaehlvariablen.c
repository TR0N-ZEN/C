#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  
  for (int x = 5; x > 0; --x) {
    printf("%i",x);
  };
  
  for (int x = 5; x > 0; x--) {
    printf("%i",x);
  };
  
  int x = 5;
  //first checked if it can be run and then executed if if it can be run
  while( x > 0 ) {
    printf("%i",x);
    x--;
  };
  
  x = 5;
  //first checked if it can be run and then executed if if it can be run
  while( x > 0 ) {
    printf("%i",x);
    --x;
  };
  
  x = 5;
  //will be run once ina nay case and then checked if it can be run again
  do {
    printf("%i", x);
    --x;
  } while ( x > 0 );
  
  x = 5;
  //will be run once ina nay case and then checked if it can be run again
  do {
    printf("%i", x);
    x--;
  } while ( x > 0 );
  
  return 0;
 }
