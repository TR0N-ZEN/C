#include <stdio.h>

typedef struct Nodes * pointer_to_node;
typedef struct Nodes
{
  int value;
  pointer_to_node next;
} Node;
int sorted[];
int list[];
void quicksort(pointer_to_node pointer_to_list, int length)
{
  int pivot_index = length/2; //length = 2*pivot_index || length = 2*pivot_index + 1
  int pivot_element = list[pivot_index];
  Node smaller[length-1];
  Node bigger[length-1];
  int i = j = 0;
  for(int a = 0; a < length; a++)
  {
    if (pivot_element < list[a])
    {
      bigger[i];
      if (i > 0) { bigger[i-1].next = &bigger[i]; }
      i++;
    }
    else
    {
      smaller[j];
      if (j > 0) { smaller[j-1].next = &smaller[j]; }
      j++;
    }
  }
  quicksort(&smaller[0], j+1);
  quicksort(&bigger[0], i+1);
  sorted[j];
  //return j+1; // index/depth of the pivot element since there are j smaller items
}


int main ()
{
  int list_length = 10;
  int list[list_length];
  //getting user input
  for (int a = 0; a < list_length; a++)
  {
    printf("Waiting for input of number %i: ", a+1);
    scanf("%i", &list[a]);
  }
  //print list
  printf("[ %i, ", list[0]);
  for (int a = 1; a < list_length - 1; a++)
  {
    printf("%i, ", list[a]);
  }
  printf("%i ]", list[list_length - 1]);
  //algorithm execution
  //quicksort(list, list_length);
}