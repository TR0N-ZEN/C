#include <stdio.h>

int main() {
  int list[] = {1 ,2 ,3 ,4};
  int *pointer_to_list = list;

  // Is pointer_to_list automatically dereferenced when using square brackets to access indices?
  printf("%d\n", pointer_to_list[3]);
  // yes it is

};
