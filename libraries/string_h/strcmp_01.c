/* The code in this file compares strings (a string is a series of characters)
 * and uses the function `strcmp` for comparison and
 * it the function `printf` to write text to your terminal.
 * Both function are not defined in this file
 * but in something called a library.
 * The functions are imported from their respective libraries:
 * `printf` through the line */
#include <stdio.h>
/* `strcmp` through the line */
#include <string.h>
/* Later on the variable `EXIT_SUCCESS` is used.
 * It also is not defined in this file but imported through */
#include <stdlib.h>


void String_Vergleich(char s1[], char s2[]) {
  int ret = strcmp (s1, s2);
  /*
   * How the function `strcmp` works can be looked up in
   * the manual page either through typing
   *   man 3 strcmp
   * in your terminal and pressing enter
   * or read into the following webpages
   *   https://manpages.org/strcmp/3
   *   https://man7.org/linux/man-pages/man3/strcmp.3.html ◄───┐
   *   https://linux.die.net/man/3/strcmp ◄────────────────────┼──── these three have the same text
   *   https://man.archlinux.org/man/strcmp.3.de ◄─────────────┘
   *   https://sourceware.org/glibc/manual/latest/html_mono/libc.html#String_002fArray-Comparison
   */
   if(ret == 0)
      printf("%s == %s\n", s1, s2);
   else
      printf("%s %c %s\n",s1,( (ret < 0) ?'<' :'>'), s2);
}


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
