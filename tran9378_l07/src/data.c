/**
 * -------------------------------------
 * @file  data.c
 * Data Type Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
// Includes
#include <stdio.h>

#include "data.h"

// Functions

int data_string(char *string, size_t size, data_ptr data) {
    return snprintf(string, size, "%d", *data);
}

void data_copy(data_ptr target, data_ptr source) {
    *target = *source;
}

int data_compare(data_ptr source, data_ptr target) {
    int result = 0;

    if(*source < *target) {
        result = -1;
    } else if(*source > *target) {
        result = 1;
    }
    return (result);
}

void data_free(data_ptr *source) {
    free(*source);
    *source = NULL;
    return;
}
