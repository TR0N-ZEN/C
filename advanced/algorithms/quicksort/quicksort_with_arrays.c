#include <stdio.h>

// compile in debug mode
//   gcc -g -o quicksort_with_arrays.o quicksort_with_arrays.c
// run with debugger
//   gdb ./quicksort_with_arrays.o

int sorted[9];

/*
 * assumes unique values inside list
 * Parameters:
 *   list: pointer to the first element of a list of integers
 *   length: length of list
 *   offset: number of smaller numbers inside the array given to the root function call of the recursion on `quicksort(...)`
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
    bigger[  !value_is_bigger*max_index       // If `value` is not bigger, set the index to `max_index`
           + value_is_bigger*i ]              // or if `value` is bigger, set the index to `i`.
      = value;                                // Put the value into the array `smaller` at the index set in the previous two lines.

    i += value_is_bigger;                     // If `value` is bigger, increase the displacement for
                                              // insertion in to the array named `bigger`.

    smaller[  !value_is_smaller*max_index     // If `value` is not smaller, set the index to `max_index`
            + value_is_smaller*j ]            // or if `value` is smaller, set the index to `j`.
      = value;                                // Put the value into the array `smaller` at the index set in the previous two lines.

    j += value_is_smaller;                    // If the value is smaller, increase the displacement
                                              // for insertion in to the array named `smaller`.
  }
  sorted[offset+j] = pivot_value;

  quicksort(bigger,i,offset+j+1);
  quicksort(smaller,j,offset);
  return;
}


int main ()
{
  int list_length = 9;
  int list[] = {6,1,7,5,4,9,3,8,2};
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
