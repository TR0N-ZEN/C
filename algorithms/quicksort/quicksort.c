#include <stdio.h>

typedef struct Nodes * pointer_to_node;
typedef struct Nodes
{
    int value;
    pointer_to_node next;
} Node;


/*
pointer_to_list quicksort(pointer_to_list pointer_to_list, int length)
{
    int pivot_index = length/2; //length = 2*pivot_index || length = 2*pivot_index + 1
    int pivot_element = list[pivot_index];
    int i = j = 0;
    for(int a = 0; a < length; a++)
    {
        if (pivot_element < list[a]) { bigger[i]; i++; }
        else { smaller[j]; j++; }
    }
    trim_list();
}
*/

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