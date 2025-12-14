#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * To use code (that contains functions, datatypes and variables)
 * from elswhere you have to import that code.
 * The stuff thing that is imported is called a library and
 * part of a library is its object file.
 * An object file is created from a file that contains regular C code.
 * The compiler (that is `gcc` here) though needs to be instructed to
 * create an object file as an output.
 * So compile file containing the C code with the command
 *   gcc -c custom-library-code.c
 * the manual page for `gcc` displayed by the command
 *   man 1 gcc
 *  states more details on the specifics of calling the commdand `gcc -c ...`
 *    -c  Compile or assemble the source files, but do not link.
 *        The linking stage simply is not done.  The ultimate output is in the
 *        form of an object file for each source file.
 *  So calling
 *    gcc -c custom-library-code.c
 *  will create the file
 *    custom-library-code.o
 *  which is the object file.
 *  Nextup read the file
 *    listing_01.c
 */

void String_Vergleich(char s1[], char s2[]) {
   int ret = strcmp (s1, s2);
   if(ret == 0)
      printf("%s == %s\n", s1, s2);
   else
      printf("%s %c %s\n",s1,( (ret < 0) ?'<' :'>'), s2);
}
