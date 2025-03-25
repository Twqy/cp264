/**
 * -------------------------------------
 * @file  main.c
 * Lab 8 Main Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

#include "min_heap.h"

#define MAX_STRING 80
#define SEP "------------------------------------------------\n"

/**
 * Simple heap testing.
 */
void test_heap(void) {
    // Define some arbitrary test data
    int numbers1[] = {11, 7, 15, 6, 9, 12, 18, 8};
    int count = sizeof numbers1 / sizeof *numbers1;

    // Define a heap
    min_heap *source = min_heap_initialize(HEAP_INIT);
    printf("Insert test values into heap:\n");

    for(int i = 0; i < count; i++) {
        printf("  insert: %d\n", numbers1[i]);
        min_heap_insert(source, numbers1[i]);
    }
    min_heap_print(source);

    // Check the heap for validity.
    printf("Heap valid: %d\n", min_heap_valid(source));
    printf(SEP);
    // Remove all data from the heap and copy to an array.
    printf("Remove all data from heap:\n");

    while(!min_heap_empty(source)) {
        printf("%d, ", min_heap_remove(source));
    }
    printf("\n");
    printf(SEP);
    printf("Use heapify with data\n");
    min_heap_heapify(source, numbers1, count);
    printf("Contents of heap in level order:\n");
    min_heap_print(source);
    printf(SEP);
    int key = 13;
    printf("Call replace on root node\n");
    printf("Replacement value: %d\n", key);
    int value = min_heap_replace(source, key);
    printf("Replaced (root) value: %d\n", value);
    printf("Contents of heap in level order:\n");
    min_heap_print(source);
    printf(SEP);
    printf("Heap valid: %d\n", min_heap_valid(source));
    printf("Free the heap\n");
    min_heap_free(&source);
    printf(SEP);
    printf("Heap Sort:\n");
    heap_sort(numbers1, count);
    printf("after sorting: {");

    for(int i = 0; i < count; i++) {
        printf("%d, ", numbers1[i]);
    }
    printf("}\n");

}

/**
 * @param argc - unused
 * @param argv - unused
 * @return EXIT_SUCCESS
 * */
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    test_heap();

    return (EXIT_SUCCESS);
}
