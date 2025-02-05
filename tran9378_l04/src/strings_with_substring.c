/**
 * -------------------------------------
 * @file  strings_with_substring.c
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
 * Traverses every string in strings and prints the strings that contain substr. Case must match.
 *
 * @param data - the strings_array struct to traverse
 * @param substr - the substring to look for in each string
 */

void strings_with_substring(strings_array *data, char *substr) {
    for (int i = 0; i < data->lines; i++) {
        char *str = data->strings[i];
        int found = 0;
        int j = 0;
        int k = 0;
        while (str[j] != '\0') {
            while (str[j + k] == substr[k] && substr[k] != '\0') {
                k++;
            }
            if (substr[k] == '\0') {
                found = 1;
                break;
            }
            k = 0;
            j++;
        }
        if (found) {
            printf("%s\n", str);
        }
    }
}
