#include <stdbool.h>

struct Square
{
  int x0,y0,x1,y1, x2,y2,x3,y3;
};

int main ()
{
  struct Square square1;
  square1.x0 = -1; square1.y0 =  1;
  square1.x1 =  1; square1.y1 =  1;
  square1.x2 =  1; square1.y2 = -1;
  square1.x3 = -1; square1.y3 = -1;
}
