#include <stdio.h>

//typedef struct nodes * pointer_to_node;
typedef struct node
{
  int value;
  struct node * next; // next is a pointer to a 'struct node'/'Node'
} Node;

int get_value_at_index(Node node, int depth)
{
  if (depth == 0) { return node.value; }
  --depth;
  Node next_node = *(node.next); // *(node.next) <=> node->next oder?
  return get_value_at_index(next_node, depth);
}

int get_value_at_index_ver2(Node node, int depth)
{
  if (depth == 0) { return node.value; }
  if (depth == 1) { return (node.next)->value; } // using arrow operator to omit last recursion
  --depth;
  return get_value_at_index_ver2(*(node.next), depth); // not creating intermediate variable named 'next_node'
}

int main()
{
  int b = 5;
  Node nodelist[b];
  for (int a = 0; a < b; a++)
  {
    nodelist[a].value = a;
    //nodelist[a].next = NULL;
    if (a > 0)
    {
      nodelist[a-1].next = &(nodelist[a]);
    }
  }
  for (int a = 0; a < b; a++)
  {
    printf("%i = %i ?\n", nodelist[a].value, (*(nodelist[a].next)).value); // (*(nodelist[a].next)).value <=> (*nodelist[a].next).value <=> nodelist[a].next->value
  }
  for (int a = 0; a < b; a++)
  {
    printf("%i = %i ?\n", get_value_at_index(nodelist[0], a), (*(nodelist[a].next)).value); // (*(nodelist[a].next)).value <=> (*nodelist[a].next).value <=> nodelist[a].next->value
  }
  for (int a = 0; a < b; a++)
  {
    printf("%i = %i ?\n", get_value_at_index_ver2(nodelist[0], a), (*(nodelist[a].next)).value); // (*(nodelist[a].next)).value <=> (*nodelist[a].next).value <=> nodelist[a].next->value
  }
}
