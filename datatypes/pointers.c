#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a = 20; /*the varible type is int (integer)*/
int* b = &a; /*the variable type is int* meaning it is a pointer to an integer, not an integer which would be typedefined by simply int*/
int string_recovery(); // Declared but not defined/initialised. But since it is declared it can be called although it isnt defined/initialised.

void pause() {
    printf ( "Press [Enter] to continue..." );
    fflush ( stdout );
    getchar();
}

int give_a() {
    return a;
};

int* give_pointer_a() {
    return &a;
};

int* give_pointer_b() {
    return b;
};

int give_value_pointer_b_points_at() {
    return *b;
};

void pointer_demo() {
    printf("START:\t'pointer_demo'");
    printf("value(a)\tmemory address(a)\tmemory address(b)\tvalue(b)\n");
    printf("%d\t\t%x\t\t\t%x\t\t\t%d\n", give_a(), give_pointer_a(), give_pointer_b(), give_value_pointer_b_points_at());
    printf("END:\t'pointer_demo'");
}

int main() {
    printf("START:\t'main'");
    pause();
    string_recovery();
    printf("END:\t'main'");
    pause();
    return 0;
};

void string_recovery() {
    printf("START:\t'string_recovery'");
    char string[10]; /* ( array | list ) of characters with space for 10 charcters*/
    char* pointerarray[10]; /* ( array | list ) of ( memory address | pointer )s to characters with space for 10 of such*/
    char text[10]; /* ( array | list ) of characters with space for 10 charcters*/
    printf("Type sth. 10 characters long: ");
    scanf("%s", string);
    printf("String you typed (red via 'string'):\t%s\n", string);
    printf("Memory address (red via '&string[0]') is:\t%x\n", &string[0]);
    char* pointer_on_string = &string[0]; //( memory address | pointer ) to the first memory address holding ( a part | first element | first character ) of string[0]
    printf("Memory address is (red via variable 'pointer_on_string'):\t%x\n", pointer_on_string);
    /**/
    for (int x = 0; x < 10; x++) {
        pointerarray[x] = pointer_on_string;
        pointer_on_string++;
        printf("%d\n",pointer_on_string);
    };
    char* pointer;
    for (int x = 0; x < 10; x++) {
        pointer = pointerarray[x];
        text[x] = *pointer; /*the * before the variable name the decodation of the variable, which has to be of type pointer, and throws out the value that is stored in the address the pointer contained/
        /*the variable called pointer is used as a transmitter which can be dereferenced with the *;
         in the end the arrays string[10] and text[10] should be the same*/
    };
    printf("You typed (pointer resolution):\t%s\n", text);
    /**/
    printf("END:\t'string_recovery'");
};
