/**
 * -------------------------------------
 * @file  sum_integers.c
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

int sum_integers(void) {
    int sum = 0;
    int num;
    char input[10];

    printf("Enter integers, one per line (enter an empty line to finish):\n");

    while (1) {
        printf(": ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            input[strcspn(input, "\n")] = '\0';

            // Check for empty input to exit the loop
            if (strlen(input) == 0) {
                break;
            }

            // Check if input is a valid integer
            int is_valid = 1;
            for (int i = 0; i < strlen(input); i++) {
                if ((input[i] < '0' || input[i] > '9') && input[i] != '-' && input[i] != '+') {
                    is_valid = 0;
                    break;
                }
            }

            if (!is_valid) {
                printf("Invalid input. Please enter a valid integer.\n");
                continue;
            }

            num = atoi(input);
            sum += num;
        } else {
            printf("Error reading input.\n");
            break;
        }
    }

    return sum;
}
//gcc sum_integers.c main.c int_array_read.c sum_three_integers.c -o q1
