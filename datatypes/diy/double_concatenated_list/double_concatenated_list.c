#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "double_concatenated_list.h"



// functions for convinience

void pause() {
    printf ( "\nPress [Enter] to continue..." );
    //fflush ( stdout );
    //getchar();
    char c1;
    scanf("%c", &c1);
}

// functions

// returns pointer to next element
element* next(element* pointer_to_element) {
    return pointer_to_element->pointer_to_next_element;
}

// returns pointer to previous element
element* previous(element* pointer_to_element) {
    return pointer_to_element->pointer_to_previous_element;
}

// insert second argument after first argument
void insert_after(element* element_before, element* insert_element) {
    // a <- b
    insert_element->pointer_to_previous_element= element_before;
    // b -> c
    insert_element->pointer_to_next_element = element_before->pointer_to_next_element;
    // b <- c
    element_before->pointer_to_next_element->pointer_to_previous_element = insert_element;
    // a -> b
    element_before->pointer_to_next_element = insert_element;
}

// insert second argument before first argument
void insert_before(element* element_after, element* insert_element) {
    // b -> c
    insert_element->pointer_to_next_element = element_after;
    // a <- b
    insert_element->pointer_to_previous_element = element_after->pointer_to_previous_element;
    // a -> b
    element_after->pointer_to_previous_element->pointer_to_next_element = insert_element;
    // b <- c
    element_after->pointer_to_previous_element = insert_element;
}

// appends first argument to list which second argument points to
void append(int(number), list* pointer_to_list) {
    // reserve memory for the new element
    element* pointer_to_new_element = (element*) malloc(sizeof(element));
    
    // assign a number to the new element
    pointer_to_new_element->number = number;
    
    // assign a NULL pointer since latest element has no sucsessor
    pointer_to_new_element->pointer_to_next_element = NULL;
    pointer_to_new_element->pointer_to_previous_element = pointer_to_list->pointer_to_last_element;
    
    // forelast element gets pointer to the new element
    pointer_to_list->pointer_to_last_element->pointer_to_next_element = pointer_to_new_element;

    // new element is declared as latest element
    pointer_to_list->pointer_to_last_element = pointer_to_new_element;

    (pointer_to_list->size)++;
}

// appends as much elements containing NULL as number to the first argument as the second arguments  
void expand_by(list* pointer_to_list, int amount_of_new_elements) {
    for (int i = 0; i < amount_of_new_elements; i++) { append(pointer_to_list, NULL); }
}

// returns pointerto the list_element
int get_pointer (list* pointer_to_list, int index) {
    element* pointer_to_element = pointer_to_list->pointer_to_first_element;
    for (int i = 0; i < index; i++) { pointer_to_element = next(pointer_to_element); }
    return pointer_to_element;
}

// inserts number in list so that list stays sorted
void sorted_insert(list* pointer_to_list, element* new_element) {
    element* pointer_to_insertion_element = pointer_to_list->pointer_to_first_element;

    // index of the element in the middle of the current section of the list which pointer_to_list points to
    int middle_index = (pointer_to_list->size)/2;

    // maximum amount of bisectionings
    int max = log2(pointer_to_list->size);

    for (int i = 0; i < max; i++) {
        int pivot_element = get_pointer(pointer_to_list, middle_index);
        if (previous(pivot_element)->number < new_element->number < pivot_element->number) {
            insert_before(pivot_element, new_element);
            (pointer_to_list->size)++;
        }
        else if (pivot_element->number < pointer_to_insertion_element->number) { 
            middle_index = int (floor( middle_index/2) ) ;
        }
        else if (pivot_element->number > pointer_to_insertion_element->number) {
            middle_index = int (floor( middle_index*1.5 ));
        }
    }
}
