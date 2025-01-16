/**
 * -------------------------------------
 * @file  main.c
 * Lab 2 Main Source Code File
 * -------------------------------------
 * @author Ryan Tran, 169069378, tran9378@myls
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

#include "by_index.h"
#include "by_ptr.h"

#define MAX_SIZE 6

/**
 * Test the array traversal functions.
 *
 * @param argc - count of elements in args
 * @param argv - array of strings passed on command line
 * @return EXIT_SUCCESS
 */
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    int values[MAX_SIZE];
    long int squares[MAX_SIZE];

    printf("Using index-based arrays\n\n");
    fill_values_by_index(values, MAX_SIZE);
    fill_squares_by_index(values, squares, MAX_SIZE);
    print_by_index(values, squares, MAX_SIZE);
    printf("----------------------------------\n");
    // Reset contents of both arrays to 0s.
    // Required to make sure arrays are empty before refilling them.
    memset(values, 0, sizeof *values * MAX_SIZE);
    memset(squares, 0, sizeof *squares * MAX_SIZE);
    printf("Resetting array:\n");
    print_by_ptr(values, squares, MAX_SIZE);
    printf("----------------------------------\n");
    printf("Using pointer-based arrays\n\n");
    fill_values_by_ptr(values, MAX_SIZE);
    fill_squares_by_ptr(values, squares, MAX_SIZE);
    print_by_ptr(values, squares, MAX_SIZE);

    return EXIT_SUCCESS;
}
