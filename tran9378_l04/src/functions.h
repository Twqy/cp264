/**
 * -------------------------------------
 * @file  functions.h
 * Lab 4 Functions Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// Define return results
#define MALLOC_FAILED -1   // error code for malloc failure
#define TOO_MANY_LINES -2  // error code for array of strings size exceeded

#define MAX_LINE 128 // Max. length of a string
#define MAX_LINES 500 // Max. number of lines in an array of strings

// data structures
typedef struct {
    char **strings;  // pointer to array of strings
    int capacity;    // maximum capacity of strings
    int lines;       // number of lines stored in strings
} strings_array;

/**
 * Initializes a strings_array variable.
 *
 * @param capacity - the number of strings the struct can store
 * @return - a pointer to a new strings_array struct.
 */
strings_array* initialize_strings_array(const int capacity);

/**
 * Frees memory from a strings_array variable.
 *
 * @param data - the strings_array struct to free
 */
void free_strings_array(strings_array **data);

/**
 * Reads consecutive lines of text from fp until either the end of file is reached or
 * the end of the array of pointers is reached.
 * Each input line is stored in dynamic storage and it is accessed/referenced by the strings array.
 * That is, strings[0] points to the FIRST input line,
 *          strings[1] points to the SECOND input line, and so on.
 *
 * @param data - the strings_array struct to fill with strings
 * @param fp - input file pointer
 * @return - number of lines read; MALLOC_FAILED: if malloc fails; TOO_MANY_LINES: if size of strings exceeded
 */
int read_strings(strings_array *data, FILE *fp);

/**
 * Traverses every string in strings and prints the strings that contain substr. Case must match.
 *
 * @param data - the strings_array struct to traverse
 * @param substr - the substring to look for in each string
 */
void strings_with_substring(strings_array *data, char *substr);

/**
 * Traverses every string in strings and copies all strings shorter than length to the short_lines file,
 * and allstrings equal to or longer than length to the long_lines file.
 *
 * @param data - the strings_array struct to traverse
 * @param fp_short - output file pointer
 * @param fp_long - output file pointer
 * @param length - comparison length for strings
 */
void strings_length(strings_array *data, FILE *fp_short, FILE *fp_long, int length);

#endif /* FUNCTIONS_H_ */
