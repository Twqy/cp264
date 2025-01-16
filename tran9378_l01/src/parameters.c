/**
 * -------------------------------------
 * @file  parameters.c
 * -------------------------------------
 * @author Ryan, 169069378, tran9378@mylaurier.ca
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 */
#include "parameters.h"

/**
 * Prints all parameters passed on command line.
 *
 * @param argc - size of argv
 * @param argv - array of strings passed on command line
 */
void parameters(int argc, char *const argv[]) {
    printf("Program Parameters:\n\n");

    if(argc == 1) {
        // No user program parameters specified.
        printf("  No user parameters specified.\n\n");
        printf("  Argument 0 is a system default, and is always passed to the main program.\n");
        printf("  Argument 0 is the path and name of the executable file.\n\n");
        printf("  argc: %d\n", argc);
        printf("  argv[0] = \"%s\"\n", argv[0]);
    } else {
        // User program parameters specified.
        printf("  argc: %d\n\n", argc);

        for(int i = 0; i < argc; i++) {
            printf("  argv[%d] = \"%s\"\n", i, argv[i]);
        }
    }
}
