#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void pause() {
    printf ( "\nPress [Enter] to continue..." );
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
    p_new_element->number = number;
    p_new_element->pointer_to_next_element = NULL;
    p_element_before->pointer_to_next_element = p_new_element;
    p_element_before = p_new_element;
}

int listsize;
void extending_list()
{
    int value;
    printf("\nEnter an integer for how long your list will be for now: ");
    scanf("%i", &listsize);
    for (int i = 0; i < listsize; i++)
    {
        printf("\nEnter an integer value: ");
        scanf("%i", &value);
        append_element(value);
    }
}

void sorted_insert()
{
    int value;
    printf("\nPlease enter and integer you want to perform a serted insert on: ");
    scanf("%i", &value);
    element* p_current_element = &element0;
    element* p_next_element = p_current_element->pointer_to_next_element;
    for ( int i = 0; i < listsize; i++ ) {
        if (p_current_element->number < value < p_next_element->number) {
            element* p_new_element = (element*) malloc(sizeof(element));
            p_new_element->number = value;
            p_current_element->pointer_to_next_element = p_new_element;
            p_new_element->pointer_to_next_element = p_next_element;
        }
    }
    listsize++;
}

void loop_through_list()
{
    printf("\nSTART:\t'loop_through_list'");
    element current_element = element0;
    for ( int i =  0; i < listsize; i++) {
        printf("\n%i", current_element.number);
        current_element = *(current_element.pointer_to_next_element);
    }
    printf("\nEND:\t'loop_through_list'");
}

int main()
{
    element0.number = 0;
    p_element_before = &element0;
    extending_list();
    pause();
    loop_through_list();
    pause();
    sorted_insert();
    pause();
}