#include <stdlib.h>
#include "custom-library-code.h"

/*
 * In this file the function
 *   String_Vergleich
 * is called but it is not defined here.
 * Since it is not defined in this file
 * it has to be imported.
 * For example the macro
 *   EXIT_SUCCESS
 * ,which is text that will be replaced for a number,
 * has to be imported.
 * The number used to replace the text is defined in
 * a library named `stdlib`.
 * The library is imported by the line of code
 *   #include <stdlib.h>
 * And similarly the custom library is imported by
 *   #include "custom-library-code.h"
 * which also requires the files
 *   custom-library-code.h
 *   custom-library-code.o
 * to exist, for this example in the same folder
 * as this file.
 * And the compiler is instructed to read the
 *   custom-library-code.c
 * file, so that calling the compiler looks like
 *   gcc -o listing_01 listing_01.c custom-library-code.o
 */

int main(void) {
   char str1[] = "aaa";
   char str2[] = "aab";
   char str3[] = "abb";

   String_Vergleich(str1, str2);
   String_Vergleich(str1, str3);
   String_Vergleich(str3, str2);
   String_Vergleich(str1, str1);
   return EXIT_SUCCESS;
}
