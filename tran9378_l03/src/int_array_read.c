/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author Ryan Tran, 169069378, tran9378@myls.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void int_array_read(int *array, int size) {
    int count = 0;
    char input[10];

    printf("Enter %d values for an array of int:\n", size);

    while (count < size) {
        printf("Value for index %d: ", count);
        if (fgets(input, sizeof(input), stdin) != NULL) {
            input[strcspn(input, "\n")] = '\0';

            // Check if input is a valid integer
            int is_valid = 1;
            for (int i = 0; i < strlen(input); i++) {
                if ((input[i] < '0' || input[i] > '9') && (i != 0 || (input[i] != '-' && input[i] != '+'))) {
                    is_valid = 0;
                    break;
                }
            }

            if (!is_valid) {
                printf("Not a valid integer\n");
                continue;
            }

            array[count] = atoi(input);
            count++;
        }
    }
}