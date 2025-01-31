/**
 * -------------------------------------
 * @file  functions.h
 * Lab 3 Functions Header File
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

#define STRING_SMALL 20
#define STRING_BIG 1024

/**
 * Reads and sums a series of integers read one at a time from the keyboard.
 * Stop reading when a non-integer is entered.
 * Prompt: "Enter integers, one per line: "
 *
 * @return - the sum of integers read from the keyboard
 */
int sum_integers(void);

/**
 * Reads and sums three comma-delimited integers on the same line from the keyboard.
 * Continues until a line of integers is correctly entered.
 * Prompt: "Enter three comma-separated integers: "
 * Error: "The integers were not properly entered.\n"
 *
 * @return - the sum of integers read from the keyboard
 */
int sum_three_integers(void);

/**
 * Reads size integers from the keyboard into an array of int.
 * Continues until size valid integers are read.
 * Prompt: "Enter %d values for an array of int.\n"
 * Error: "Not a valid integer\n"
 *
 * @param array - pointer to an array of int.
 * @param size - number of values to be stored in array.
 */
void int_array_read(int *array, int size);

#endif /* FUNCTIONS_H_ */
