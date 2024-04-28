#include <stdio.h>

int sorted[9];

/*
 * assumes unique values inside list
 * Parameters:
 *   list: pointer to the first element of a list of integers
 *   length: length of list
 *   offset: number of smaller numbers inside the whole recursion
 */
void quicksort(
    int *list, 
    int length,
    int offset
)
{
  if (length == 0) { return; }

  // ./experiments/01 proves flooring of integer division
  // ./experiments/02 proves automatic dereferencing of pointers when suffixed with square brackets
  int pivot_value = list[length/2];

  // arrays holding nodes with values smaller or bigger than the pivot element
  // in worst case one holds all except the pivot_value plus a last element that is used a bin
  // for all elements which are put in the other of the two (small or bigger)
  // to realize more branchless code though this is very likely not the most branchless code
  int smaller[length];
  int bigger[length];
  for (int a = 0; a < length; a++) { smaller[a] = 0; bigger[a] = 0; }

  int i = 0;
  int j = 0;

  int max_index = length-1;
  int value_is_bigger = 0;
  int value_is_smaller = 1;
  int value = 0;
  for(int a = 0; a < length; a++) {
    value = list[a];
    value_is_bigger = pivot_value<value;
    value_is_smaller = pivot_value>value;
    bigger[max_index*!value_is_bigger + i*value_is_bigger] = value;
    i += value_is_bigger;
    smaller[max_index*!value_is_smaller + j*value_is_smaller] = value;
    j += value_is_smaller;
  }
  sorted[offset+j] = pivot_value;

  // print list given as output, DELETE ME (this paragraph)
  printf("[ %i, ", sorted[0]);
  for (int a = 1; a < 8; a++) { printf("%i, ", sorted[a]); }
  printf("%i ]\n", sorted[8]);

  quicksort(bigger,i,offset+j+1);
  quicksort(smaller,j,offset);
  return;
}


int main ()
{
  int list_length = 9;
  int list[] = {1,2,3,5,4,6,7,8,9};
//  for (int a = 1; a < list_length; a++)
//  {
//    printf("Waiting for input of number %i: ", a);
//    scanf("%i", &list[a]);
//  }

  // print list given as input
  printf("[ %i, ", list[0]);
  for (int a = 1; a < list_length-1; a++)
  {
    printf("%i, ", list[a]);
  }
  printf("%i ]\n", list[list_length-1]);

  quicksort(list, list_length, 0);

  // print list given as output
  printf("[ %i, ", sorted[0]);
  for (int a = 1; a < list_length-1; a++)
  {
    printf("%i, ", sorted[a]);
  }
  printf("%i ]\n", sorted[list_length-1]);

}
