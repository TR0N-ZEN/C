======================
write your own library
======================

Assume an arbitrary listing named `listing_x.c`.
Compile it to an object file via

  gcc -c custom-library-code.c

which outputs the file named `custom-library-code.o`.


Nextup create a file named `custom-library-code.h`
being reffered to as the header file.
It contains declarations for functions, variables, datatypes etc.
that you want to export from `custom-library-code.o`.


In another file named `listing_01.c` you can include the header file via

  #include "custom-library-code.h"

to access all functions, variables, datatypes etc. available from
`custom-library-code.o`.


Building an executable file for the code inside `listing_01.c`
requires the compiler (`gcc`) to be called like the following

  gcc -o listing_01 listing_01.c custom-library-code.o



Information was gathered from
  https://en.wikibooks.org/wiki/C_Programming/Headers_and_libraries
