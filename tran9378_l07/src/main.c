/**
 * -------------------------------------
 * @file  main.c
 * Lab 7 Main Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "bst_linked.h"

/**
 * Simple BST testing.
 */
void test_bst(void) {
    // Define some arbitrary test data
    int numbers[] = {11, 7, 6, 9, 8, 15, 12, 18};
    int count = sizeof numbers / sizeof *numbers;
    data_ptr items[count];

    for(int i = 0; i < count; i++) {
        items[i] = malloc(sizeof items);
        items[i] = &numbers[i];
    }

    // Define a BST
    bst_linked *source = bst_initialize();
    printf("empty: %s\n", BOOL_STR(bst_empty(source)));
    printf("full:  %s\n", BOOL_STR(bst_full(source)));
    printf("count: %d\n", bst_count(source));
    printf("Insert test values:\n");

    for(int i = 0; i < count; i++) {
        bst_insert(source, items[i]);
    }
    bst_print(source);
    printf("empty: %s\n", BOOL_STR(bst_empty(source)));
    printf("full:  %s\n", BOOL_STR(bst_full(source)));
    printf("count: %d\n", bst_count(source));
    printf("leaf_count: %d\n", bst_leaf_count(source));
    printf("balanced: %s\n", BOOL_STR(bst_balanced(source)));
    data_ptr values[count];
    printf("inorder:   {");
    bst_inorder(source, values);

    for(int i = 0; i < bst_count(source); i++) {
        printf("%d, ", *values[i]);
    }
    printf("}\n");
    printf("Remove %d:\n", *items[0]);
    data_ptr item = items[0];
    bst_remove(source, item, item);
    printf("  removed: %d\n", *item);
    printf("inorder:  {");
    bst_inorder(source, values);

    for(int i = 0; i < bst_count(source); i++) {
        printf("%d, ", *values[i]);
    }
    printf("}\n");

    printf("Destroy the BST\n");
    bst_free(&source);
}

/**
 * Test the file and string functions.
 *
 * @param argc - unused
 * @param argv - unused
 * @return EXIT_SUCCESS
 */
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    test_bst();

    return (EXIT_SUCCESS);
}
