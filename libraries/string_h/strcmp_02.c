#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void) {
   char str1[64];
   char str2[64];
   scanf("%s", str1);
   scanf("%s", str2);
   printf("sizeof(str1): %d\tsizeof(str2): %d\n", sizeof(str1), sizeof(str2));
   printf("strlen(str1): %d\tstrlen(str2): %d\n", strlen(str1), strlen(str2));
   // assuming str1 to be the shorter string
   // the following strncmp will return zero if str1 is a prefix of str2
   printf("%d\n", strncmp (str1, str2, strlen(str1)));

   return EXIT_SUCCESS;
}
