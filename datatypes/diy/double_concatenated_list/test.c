#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "double_concatenated_list.h"


int main() {

    element first, last;

    first.number = 0;
    first.pointer_to_previous_element = NULL;
    first.pointer_to_next_element = &last;

    last.number = 1000;
    last.pointer_to_previous_element = &first;
    last.pointer_to_next_element = NULL;


    list list_001;
    list_001.pointer_to_first_element = &first;
    list_001.pointer_to_last_element = &last;
    list_001.size = 2;


    element e1;
    e1.number = 1;
    insert_after(list_001.pointer_to_first_element, &e1);

    element e2;
    e2.number = 2;
    insert_after(&e1, &e2);

    element e3;
    e2.number = 3;
    insert_before(list_001.pointer_to_last_element, &e3);
}
