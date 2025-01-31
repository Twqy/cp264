/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
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


int sum_three_integers(void) {
    int sum = 0;
    char input[30];
    char *token;
    int count;

    printf("Enter three comma-separated integers:\n");

    while (1) {
        printf(": ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            input[strcspn(input, "\n")] = '\0';

            // Split the input by commas
            count = 0;
            sum = 0;
            token = strtok(input, ",");
            while (token != NULL) {
                // Check if token is a valid integer
                int is_valid = 1;
                for (int i = 0; i < strlen(token); i++) {
                    if ((token[i] < '0' || token[i] > '9') && token[i] != '-' && token[i] != '+') {
                        is_valid = 0;
                        break;
                    }
                }

                if (!is_valid) {
                    printf("The integers were not properly entered.\n");
                    break;
                }

                // Convert token to integer and add to sum
                sum += atoi(token);
                count++;
                token = strtok(NULL, ",");
            }

            if (count == 3 && token == NULL) {
                return sum;
            } else {
                printf("The integers were not properly entered.\n");
            }
        }
    }
}
//gcc sum_integers.c main.c int_array_read.c sum_three_integers.c -o q1
