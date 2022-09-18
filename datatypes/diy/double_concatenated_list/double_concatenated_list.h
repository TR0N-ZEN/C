#ifndef FOO_DOT_H    /* This is an "include guard" */
#define FOO_DOT_H    /* prevents the file from being included twice. */
                     /* Including a header file twice causes all kinds */
                     /* of interesting problems.*/

// functions for convinience

void pause();



// definition of datatypes

typedef struct elementS {
    int number;
    struct elementS* pointer_to_next_element;
    struct elementS* pointer_to_previous_element;
} element;

typedef struct listS {
    int size;

    // declaration of the first element
    element* pointer_to_first_element;

   // declaration of the pointer to the element before the latest element
    element* pointer_to_last_element;

} list;



// functions

// returns pointer to next element
element* next(element* pointer_to_element);

// returns pointer to previous element
element* previous(element* pointer_to_element);

// insert second argument after first argument
void insert_after(element* element_before, element* insert_element);

// insert second argument before first argument
void insert_before(element* element_after, element* insert_element);

// appends first argument to list which second argument points to
void append(int(number), list* pointer_to_list); 

// appends as much elements containing NULL as number to the first argument as the second arguments  
void expand_by(list* pointer_to_list, int amount_of_new_elements);

// returns pointerto the list_element
int get_pointer (list* pointer_to_list, int index);

// inserts number in list so that list stays sorted
void sorted_insert(list* pointer_to_list, element* new_element);

#endif /* FOO_DOT_H */