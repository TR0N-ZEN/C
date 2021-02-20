#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /* definiere first_name */
    char* first_name = "John";
    /* definiere last_name */
    char last_name[] = "Doe";
    char name[100];
    if (strncmp(first_name, "John", 4) == 0) { printf("first_name right\n"); };
    if (strncmp(last_name, "Doe", 3) == 0) { printf("last_name right\n"); };
    last_name[0] = 'B';
    sprintf(name, "%s %s", first_name, last_name);
    if (strncmp(name, "John Boe", 100) == 0) { printf("Erledigt!\n"); };
    system("PAUSE");
    char grade;
    printf("Type your mark: ");
    scanf("%c", grade);
    switch (grade)
    {
        case 'A':
            printf("Nice");
            break;
        case 'B':
            printf("Good");
            break;
        case 'C':
            printf("We need to do sth.");
            break;
        default:
            printf("Invalid grade.");
    };
    return 0;
}