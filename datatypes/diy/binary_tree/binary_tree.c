#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// the defined datatype tree is just a pointer to a node
// where node is structured datatype defined later
typedef struct node* tree;

struct node
{
  int value;
  tree left;
  tree right;
};

void traverse_recursive(tree t, int i)
{
  t->value = i;
  i += 1;
  traverse_recursive(t->left, i);
  traverse_recursive(t->right, i);
}

void traverse(tree t)
{
  traverse_recursive(t, 1);
}

int main()
{
  tree t1;
  tree t2;
  tree t3;
  tree t4;
  tree t5;

  t1->left = t2;
  t1->right = t3;
  t2->left = t4;
  t2->right = t5;

  return 0;
}

