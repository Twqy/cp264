/**
 * -------------------------------------
 * @file  main.c
 * Lab 3 Testing Source Code File
 * -------------------------------------
 * @author Ryan Tran, 169069378, tran9378@myls.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <strings.h>

#define STRING_SIZE 18

/**
 * Converts an array of int to a string.
 *
 * @param buffer - pointer to string
 * @param size - maximum size of buffer
 * @param source - pointer to an array of int
 * @param count - number of integers in source
 * @return - buffer
 */
static char* int_array_string(char *buffer, size_t size, int *source, int count) {
    // Temporary string buffer for array items
    char item[STRING_SMALL];
    strncpy(buffer, "{", STRING_SMALL);

    for(int i = 0; i < (count - 1); i++) {
        sprintf(item, "%d, ", source[i]);
        strncat(buffer, item, STRING_SMALL);
    }
    if(count > 0) {
        sprintf(item, "%d", source[count - 1]);
        strncat(buffer, item, STRING_SMALL);
    }
    strncat(buffer, "}", STRING_SMALL);
    return buffer;
}

// Test functions.

static void test_sum_integers(void) {
    printf("Test: sum_integers\n\n");
    int sum = sum_integers();
    printf("Sum: %d\n\n", sum);
}

static void test_sum_three_integers(void) {
    printf("Test: sum_three_integers\n\n");
    int sum = sum_three_integers();
    printf("Sum: %d\n\n", sum);
}

static void test_int_array_read(void) {
    printf("Test: int_array_read\n\n");
    char buffer[STRING_BIG];
    int size = 4;
    int array[size];
    int_array_read(array, size);
    printf("%s\n", int_array_string(buffer, sizeof buffer, array, size));

}

/**
 * Test the Lab 3 input functions.
 *
 * @param argc - count of elements in args
 * @param args - array of strings passed on command line
 * @return EXIT_SUCCESS
 */
int main(int argc, char *args[]) {
    setbuf(stdout, NULL);

    test_sum_integers();
    test_sum_three_integers();
    test_int_array_read();
    return EXIT_SUCCESS;
}
