/**
 * -------------------------------------
 * @file  min_heap.c
 * Minimum Heap Source Code File
 * -------------------------------------
 * @author Ryan Tran, 169069378, tran9378@mylaurier.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "min_heap.h"

#define STRING_SIZE 80

// local functions

/**
 * Swaps two data values.
 *
 * @param a pointer to data.
 * @param b pointer to data.
 */
static void heap_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

/**
 * Moves the last value in source until it is in its correct location
 * in source.
 *
 * @param source - pointer to a heap
 */
static void heapify_up(min_heap *source)
{
    // your code here
    if (source == NULL || source->count <= 1)
    {
        return;
    }
    int current = source->count - 1;
    int parent;

    while (current > 0)
    {
        parent = (current - 1) / 2;
        if (source->values[current] < source->values[parent])
        {
            heap_swap(&source->values[current], &source->values[parent]);
            current = parent;
        }
        else
        {
            break; // in correct position
        }
    }
    return;
}

/**
 * Moves a value down source to its correct position.
 *
 * @param source - pointer to a heap
 */
static void heapify_down(min_heap *source)
{
    // your code here
    if (source == NULL || source->count <= 1)
    {
        return;
    }
    int current = 0; // start at root node
    int smallest;
    while ((current * 2 + 1) < source->count) // loop while current node has at least one child
    {
        int Lchild = (current * 2 + 1);
        int Rchild = (current * 2 + 2);
        smallest = Lchild;

        if (Rchild < source->count && source->values[current] > source->values[Rchild])
        {
            smallest = Rchild;
        }
        if (source->values[current] <= source->values[smallest])
        {
            break;
        }
        heap_swap(&source->values[current], &source->values[smallest]);
        current = smallest;
    }
    return;
}

// Public minimum heap functions

min_heap *min_heap_initialize(int capacity)
{
    min_heap *source = malloc(sizeof *source);
    source->values = malloc(capacity * sizeof *source->values);
    source->capacity = capacity;
    source->count = 0;
    return source;
}

void min_heap_free(min_heap **source)
{
    free((*source)->values);
    free(*source);
    *source = NULL;
    return;
}

void min_heap_heapify(min_heap *source, int *keys, int count)
{
    if (source == NULL || keys == NULL || count <= 0)
    {
        return;
    }

    for (int i = 0; i < count; i++)
    {
        min_heap_insert(source, keys[i]);
    }

    return;
}

int min_heap_empty(const min_heap *source)
{
    return (source->count == 0);
}

int min_heap_full(const min_heap *source)
{
    return (source->count == source->capacity);
}

int min_heap_count(const min_heap *source)
{
    return (source->count);
}

void min_heap_insert(min_heap *source, const int value)
{
    source->values[source->count] = value;
    source->count++;
    // Fix the heap.
    heapify_up(source);
    return;
}

int min_heap_peek(const min_heap *source)
{
    return (source->values[0]);
}

int min_heap_remove(min_heap *source)
{
    if (source == NULL || source->count == 0)
    {
        return -1;
    }

    int value = source->values[0];
    source->count--;

    if (source->count > 0)
    {
        source->values[0] = source->values[source->count];
        heapify_down(source);
    }

    return value; // Return the removed value
}

int min_heap_valid(const min_heap *source)
{
    // your code here
    if (source == NULL)
    {
        return 0;
    }
    if (source->count <= 1)
    {
        return 1;
    }
    for (int i = 0; i < source->count / 2; i++)
    {
        int Lchild = (i * 2 + 1);
        int Rchild = (i * 2 + 2);

        if (Lchild < source->count && source->values[i] > source->values[Lchild])
        {
            return 0;
        }
        if (Rchild < source->count && source->values[i] > source->values[Rchild])
        {
            return 0;
        }
    }
    return 1;
}

int min_heap_replace(min_heap *source, int replacement)
{
    if (source == NULL || source->count == 0)
    {
        return -1;
    }

    int value = source->values[0];
    source->values[0] = replacement;
    heapify_down(source);

    return value;
}

void heap_sort(int *values, int count)
{
    if (values == NULL || count <= 1)
    {
        return; // Nothing to sort
    }

    min_heap *source = min_heap_initialize(count);

    for (int i = 0; i < count; i++)
    {
        min_heap_insert(source, values[i]);
    }

    for (int i = 0; i < count; i++)
    {
        values[i] = min_heap_remove(source);
    }

    min_heap_free(&source);

    return;
}

// for testing
void min_heap_print(const min_heap *source)
{
    printf("{");

    for (int i = 0; i < source->count; i++)
    {
        printf("%d, ", source->values[i]);
    }
    printf("}\n");
    return;
}
