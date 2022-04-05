#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* tree;
struct node
{
  int value;
  tree left;
  tree right;
};

void path_rec(tree t, int i)
{
  t.value = i;
  i += 1;
  path_rec(t->left, i);
  path_rec(t->right, i);
}

void path(tree t)
{
  int i = 1;
  path_rec(t, i);
}

int main()
{
  return 0;
}