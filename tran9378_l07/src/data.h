/**
 * -------------------------------------
 * @file  data.h
 * Data Type Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef DATA_H_
#define DATA_H_

#include <stdlib.h>
#include <stdbool.h>

// Macros

#define BOOL_STR(x) ((x)?"true":"false")

#define DATA_STRING_SIZE 80

// Prototypes
/**
 * Define a data type as a pointer to an existing type.
 * Examples:
 *   typedef float *data_ptr;
 *   typedef food_struct *data_ptr;
 *   typedef movie_struct *data_ptr;
 */
typedef int *data_ptr;

/**
 * Returns a string version of a data item.
 *
 * @param string - destination string
 * @param size - maximum size of destination string
 * @param source - pointer to source data
 * @return - number of characters supposed to be written to string
 */
int data_string(char *string, size_t size, data_ptr source);

/**
 * Copies data from source to target.
 *
 * @param target - pointer to target data
 * @param source - pointer to source data
 */
void data_copy(data_ptr target, data_ptr source);

/**
 * Compares two data objects.
 *
 * @param target - pointer to target data
 * @param source - pointer to source data
 * @return - 0 if data is equal, < 0 if source < target, > 0 if source > target
 */
int data_compare(data_ptr target, data_ptr source);

/**
 * Frees contents of source.
 *
 * @param source - pointer to source data
 */
void data_free(data_ptr *source);

#endif /* DATA_H_ */
