/**
 * -------------------------------------
 * @file  min_heap.h
 * Minimum Heap Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef MAX_HEAP_H_
#define MAX_HEAP_H_

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_INIT 15 // Defines four full rows of heap

/**
 * Heap header.
 */
typedef struct
{
    int capacity; // current capacity of the heap
    int count;    // count of number of values in the heap
    int *values;  // pointer to array of data values.
} min_heap;

// Prototypes

/**
 * Initialize a heap structure
 * @return
 */
min_heap *min_heap_initialize();

/**
 * Frees heap memory.
 *
 * @param source - pointer to a heap
 */
void min_heap_free(min_heap **source);

/**
 * Create a heap from an array of values. Heap capacity must be
 * large enough to hold all values in array.
 *
 * @param source - pointer to a heap
 * @param values - array of values to insert into heap
 * @param count - number of values in values array
 */
void min_heap_heapify(min_heap *source, int *values, int count);

/**
 * Frees contents of source.
 *
 * @param source - pointer to a heap
 */
void min_heap_free(min_heap **source);

/**
 * Determines if source is empty.
 *
 * @param source - pointer to a heap
 * @return - 1 if source is empty, 0 otherwise.
 */
int min_heap_empty(const min_heap *source);

/**
 * Determines if source is full, i.e. count == capacity
 *
 * @param source - pointer to a heap
 * @return - 1 if source is full, 0 otherwise.
 */
int min_heap_full(const min_heap *source);

/**
 * Returns the number of values in source.
 *
 * @param source - pointer to a heap
 * @return - number of values in source
 */
int min_heap_count(const min_heap *source);

/**
 * Adds a value to source.
 *
 * @param source - pointer to a heap
 * @param value - the value to add to source
 */
void min_heap_insert(min_heap *source, const int value);

/**
 * Returns the value in the root of source, source is unchanged.
 *
 * @param source - pointer to a heap
 * @return - the value in the root of source
 */
int min_heap_peek(const min_heap *source);

/**
 * Removes and returns the value in the root of source.
 *
 * @param source - pointer to a heap
 * @return - the value in the root of source
 */
int min_heap_remove(min_heap *source);

/**
 * Prints the elements in source in level order.
 * (For testing only).
 *
 * @param source - pointer to a heap
 */
void min_heap_print(const min_heap *source);

/**
 * Determines if a heap is valid: i.e. all values are >= parent
 * values.
 *
 * @param source - pointer to heap
 * @return - 1 if heap is valid, 0 otherwise
 */
int min_heap_valid(const min_heap *source);

/**
 * Remove the smallest value from source and inserts a new value.
 * source count does not change.
 *
 * @param source - pointer to a heap
 * @param replacement - value to add to source
 * @return - value replaced in source
 */
int min_heap_replace(min_heap *source, int replacement);

/**
 * Sorts an array of integers.
 *
 * @param values - array of values to sort
 * @param count - number of values in values
 */
void heap_sort(int *values, int count);

#endif /* MAX_HEAP_H_ */
