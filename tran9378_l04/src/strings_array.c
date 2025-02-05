/**
 * -------------------------------------
 * @file  read_text.c
 * Lab 6 Source Code File
 * -------------------------------------
 * @author Heider Ali, 999999999, heali@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

strings_array* initialize_strings_array(const int capacity) {
    // Allocate memory to the data structure
    strings_array *data = malloc(sizeof *data);
    // Allocate memory to the array of strings
    data->strings = malloc(capacity * sizeof *data->strings);
    // Assign values to remaining attributes
    data->capacity = capacity;
    data->lines = 0;
    return data;
}

void free_strings_array(strings_array **data) {
    // Free the individual strings
    for(int i = 0; i < (*data)->capacity; i++) {
        free((*data)->strings[i]);
        (*data)->strings[i] = NULL;
    }
    // Free the data structure
    free(*data);
    *data = NULL;
}

int read_strings(strings_array *data, FILE *fp) {
    int lines = 0;        // Initialize the line count
    char line[MAX_LINE];  // Local storage for the current line of text
    int length = 0;       // The length of a line from the file

    while((lines >= 0) && (fgets(line, sizeof line, fp) != NULL)) {

        // Verify room in strings
        if(lines < data->capacity) {
            // Trim end of line characters (Windows, Mac, or Linux)
            length = strcspn(line, "\r\n");
            line[length] = '\0';

            // Allocate and verify dynamic storage for line with space for trailing NULL
            if((data->strings[lines] = malloc(length + 1)) != NULL) {
                // Copy line to strings
                strcpy(data->strings[lines], line);
                lines++;  // Increment the line count.
            } else {
                // Set error code
                lines = MALLOC_FAILED;
            }
        } else {
            // Set error code
            lines = TOO_MANY_LINES;
        }
    }
    if(lines > 0) {
        data->lines = lines;
    }
    return lines;
}

