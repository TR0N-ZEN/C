#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// functions for convinience

void pause() {
    printf ( "\nPress [Enter] to continue..." );
    //fflush ( stdout );
    //getchar();
    char c1;
    scanf("%c", &c1);
}



// definition of datatypes

typedef struct elements {
    int number;
    struct elements* pointer_to_next_element;
    // element pointer_to_next_element; // this line doesn't work as expected
} element;



// global variables
    
    // declaration of the first element 
    element first_element;

    // declaration of the pointer to the element before the latest element
    element* pointer_to_element_before;

    int listsize;


// functions

element* next(element* pointer_to_element) {
    return pointer_to_element->pointer_to_next_element;
}

void append(int(number)) {
    // reserve memory for the new element
    element* pointer_to_new_element = (element*) malloc(sizeof(element));
    
    // assign a number to the new element
    pointer_to_new_element->number = number;
    
    // assign a NULL pointer since latest element has no sucsessor
    pointer_to_new_element->pointer_to_next_element = NULL;
    
    pointer_to_element_before->pointer_to_next_element = pointer_to_new_element;
    pointer_to_element_before = pointer_to_new_element;
}



void extending_list() {
    int value;
    printf("\nEnter an integer for how long your list will be for now: ");
    scanf("%i", &listsize);
    for (int i = 0; i < listsize; i++) {
        printf("\nEnter an integer value: ");
        scanf("%i", &value);
        append(value);
    }
}

void sorted_insert() {
    int value;
    printf("\nPlease enter and integer you want to perform a serted insert on: ");
    scanf("%i", &value);
    element* p_current_element = &first_element;
    element* p_next_element = p_current_element->pointer_to_next_element;
    for ( int i = 0; i < listsize; i++ ) {
        if (p_current_element->number < value < p_next_element->number) {
            element* pointer_to_new_element = (element*) malloc(sizeof(element));
            pointer_to_new_element->number = value;
            p_current_element->pointer_to_next_element = pointer_to_new_element;
            pointer_to_new_element->pointer_to_next_element = p_next_element;
        }
    }
    listsize++;
}

void loop_through_list() {
    printf("\nSTART:\t'loop_through_list'");
    element current_element = first_element;
    for ( int i =  0; i < listsize; i++) {
        printf("\n%i", current_element.number);
        current_element = *(current_element.pointer_to_next_element);
    }
    printf("\nEND:\t'loop_through_list'");
}

int main() {
    first_element.number = 0;
    pointer_to_element_before = &first_element;
    extending_list();
    pause();
    loop_through_list();
    pause();
    sorted_insert();
    pause();
}

