#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void pause() {
    printf ( "Press [Enter] to continue..." );
    //fflush ( stdout );
    //getchar();
    char c1;
    scanf("%c", &c1);
}

typedef struct elements {
    int number;
    struct elements* pointer_to_next_element;
} element;

element element0;
element* p_element_before;

void append_element(int(number)) {
    element* p_new_element = (element*) malloc(sizeof(element));
    p_element_before->pointer_to_next_element = p_new_element;
    p_new_element->number = number;
    p_new_element->pointer_to_next_element = NULL;
    p_element_before = p_new_element;
}

void extending_list() {
    int listsize;
    int value;
    scanf("Enter an integer for how long your list will be for now: %i", &listsize);
    for (int i = 0; i < listsize, i++;) {
        scanf("Enter an integer value: %i", &value);
        append_element(value);
    }
}

int main() {
    element0.number = 0;
    printf("%i\n", element0.number);
    p_element_before = &element0;
    append_element(1);
    printf("%i\n", p_element_before->number);
    printf("%i\t%i\n", element0.pointer_to_next_element, p_element_before );
    pause();
}