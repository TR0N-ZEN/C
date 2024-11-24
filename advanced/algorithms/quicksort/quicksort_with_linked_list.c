// compile in debug mode
//   gcc -g -o quicksort_with_linked_list.o quicksort_with_linked_list.c
// run with debugger
//   gdb ./quicksort_with_linked_list.o

#include <stdio.h>
#include <stdlib.h>

# define size 9

// defines data structure for 'single linked list'
typedef struct Nodes * pointer_to_node;
typedef struct Nodes
{
  int value;
  pointer_to_node next;
} Node;

// global arrays, why are they here we concatenate 'Nodes' I thought?
int sorted[size];
int list[size];

// helper function for `quicksort(...)`
pointer_to_node get_pointer_to_last_node(
  pointer_to_node node);

pointer_to_node quicksort(
  pointer_to_node pointer_to_list
)
{
  // of pointer_to_list is a pointer to a node with no next node return the pointer to this node
  // because the subproblem of sorting this one-element-long list is solved
  if(pointer_to_list->next == NULL) { return pointer_to_list; }

  pointer_to_node pivot_node = pointer_to_list;
  pointer_to_node considered_node = NULL;

  pointer_to_node list_smaller = NULL;
  pointer_to_node list_smaller_newest = NULL; // to avoid iterating through list_smaller when appending an item
  pointer_to_node list_bigger = NULL;
  pointer_to_node list_bigger_newest = NULL; // to avoid iterating through list_bigger when appending an item

  pointer_to_node next = pointer_to_list->next;
  do
  {
    considered_node = next;
    next = considered_node->next;
    if (considered_node->value < pivot_node->value)
    {
      if (list_smaller == NULL) { list_smaller = considered_node; }
      list_smaller_newest = considered_node;
    }
    else
    {
      if (list_bigger== NULL) { list_bigger = considered_node; }
      list_bigger_newest = considered_node;
    }
    considered_node->next = NULL;
  } while(next->next != NULL);

  if (list_smaller != NULL) {
    list_smaller = quicksort(list_smaller);
    get_pointer_to_last_node(list_smaller)
	  ->next = pivot_node;
  }
  if (list_bigger != NULL) {
    pivot_node->next = quicksort(list_bigger);
  } else { pivot_node->next = NULL;  }

  // since only the calling quicksort knows which of the returned lists
  // contains the smaller and which one the bigger nodes
  // so return pointer to the beginning of the lists smaller and bigger
  // and for the smaller follow the next pointer of the nodes until NULL

  return list_smaller;
}

pointer_to_node get_pointer_to_last_node(
  pointer_to_node node_p)
{
  while (node_p->next != NULL) { node_p = node_p->next; } 
  return node_p;
}

int main ()
{
  int array[] = {6,1,7,5,4,9,3,8,2};

  Node first_node;
  first_node.value = array[0];
  pointer_to_node node = &first_node;
  pointer_to_node next_node = NULL; 

  for(int idx = 0; idx < size-1; idx++)
  {
    next_node = malloc(sizeof(Node));
    next_node->value = array[idx+1];
    next_node->next = NULL;
    node->next = next_node;
    node = next_node;
  }

  // getting user input
  // for (int a = 0; a < list_length; a++)
  // {
  //   printf("Waiting for input of number %i: ", a+1);
  //   scanf("%i", &list[a]);
  // }

  // print list
  pointer_to_node p = &first_node;
  printf("[ %i, ", p->value);
  while (p->next != NULL && p->next->next != NULL) {
    p = p->next; printf("%i, ", p->value); }
  if (p->next != NULL) { printf("%i ]\n", p->next->value); }
  else { printf(" ]\n"); }

  return 0;

  // algorithm execution
  pointer_to_node pointer_to_head_of_sorted_list = quicksort(&first_node);

  // print list
  p = pointer_to_head_of_sorted_list;
  printf("[ %i, ", p->value);
  while (p->next != NULL && p->next->next != NULL) {
    p = p->next; printf("%i, ", p->value); }
  if (p->next != NULL) { printf("%i ]", p->next->value); }
  else { printf(" \n]"); }

  return 0;
}
