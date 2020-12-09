#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
/*
typedef DATATYPE DATATYPE-IDENTIFIER;
DATATYPE-IDENTIFIER VARIABLE-IDENTIFIER;
*/
typedef int integerlist[20]; //array of twenty integers is defined as datatype just like int (=integer) is
integerlist Feld; //Feld is a variable of type array1, so it is an array with space for ten integers

/*
typedef struct DATATYPE-IDENTIFIER {
    ...
    ...
    ...
} VARIABLE-IDENTIFIER;
*/

typedef struct students {   /*struct will create an object which can be thought of as a list containing entries/variables of different datatypes*/
    char name[10];          /*first entry will be an array of length ten for characters and the name name which is the replacement for the indexnumber which would be the comparable aspect in an array*/
    char major[20];         /*second entry is a list of charcters with length 20 and the name major which is the replacement for the indexnumber which would be the comparable aspect in an array...how to call them will be shown*/
    int number;             /*thrid entry is an integer called number*/
    float gpa;              /*fourth is a float value named gpa*/
} student;
/*
struct students studentlist[50];
<=>
student studentlist[50];
*/
student studentlist[50]; /*studentlist is an array with entries of type student, the struct we defined before, so each entry contains basically said another list, whichs elements are of different datatypes and have words as indexes*/
//printf(studentlist[0]);//prints a memory address aka pointer to the object's starting memory cell


int number = 0;
int main() {
    strcpy(studentlist[number].name, "Theo");
    strcpy(studentlist[number].major, "computer science");
    studentlist[number].number = 0;
    studentlist[number].gpa = 4.0;

    printf("name\tnumber\tmajor\t\tgpa\n");
    printf("%s\t%i\t%s\t%f\n", studentlist[0].name, studentlist[0].number, studentlist[0].major, studentlist[0].gpa);

    number = 1;
    char yesno[1];
    printf("Enter further students? y/n:\t");
    scanf("%s", yesno);
    if (strcmp(yesno, "y") == 0) {
        bool go_on = true;
        char name[20], major[30];
        float gpa;
        while (go_on) {
            printf("name:\t");
            scanf("%s", name);
            printf("major:\t");
            scanf("%s", major);
            printf("gpa:\t");
            scanf("%f", &gpa);
            studentlist[number];
            strcpy(studentlist[number].name, name);
            strcpy(studentlist[number].major, major);
            studentlist[number].number = number;
            studentlist[number].gpa = gpa;
            printf("Wanna go on? y/n\t");
            scanf("%s", yesno);
            if (strcmp(yesno, "n") == 0) {
                go_on = false;
            }
            else {
                number++;
            }
        }
    }
    printf("name\tnumber\tmajor\t\tgpa\n");
    for (int counter = 0; counter <= number; counter++) {
        printf("%s\t%i\t%s\t%f\n", studentlist[counter].name, studentlist[counter].number, studentlist[counter].major, studentlist[counter].gpa);
    }
}
