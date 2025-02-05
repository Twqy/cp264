/**
 * -------------------------------------
 * @file  strings_length.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author ryan tran, 169609378, tran9378@mylaurier.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

/**
 * Traverses every string in strings and copies all strings shorter than length to the short_lines file,
 * and allstrings equal to or longer than length to the long_lines file.
 *
 * @param data - the strings_array struct to traverse
 * @param fp_short - output file pointer
 * @param fp_long - output file pointer
 * @param length - comparison length for strings
 */

void strings_length(strings_array *data, FILE *fp_short, FILE *fp_long, int length) {

    for (int a = 0; a < data->lines; a++) {
        char *str = data->strings[a];
        int str_len = strlen(str);

        if (str_len >= length) {
            fprintf(fp_long, "%s\n", str);
        } else {
            fprintf(fp_short, "%s\n", str);
        }
    }
}

/** 
typedef struct {
    char **strings;  // pointer to array of strings
    int capacity;    // maximum capacity of strings
    int lines;       // number of lines stored in strings
} strings_array;
*/

//gcc strings_length.c  strings_with_substring.c main.c strings_array.c -o q1 