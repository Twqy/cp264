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

#include "data.h"
#include "avl_linked.h"

#define MAX_STRING 80

/**
 * Simple AVL testing.
 */
void test_avl(void) {
    char buffer[MAX_STRING];
    // Define some arbitrary test data
    int numbers[] = {11, 7, 6, 9, 8, 15, 12, 18};
    int count = sizeof numbers / sizeof *numbers;
    data_ptr items[count];

    for(int i = 0; i < count; i++) {
        items[i] = malloc(sizeof items);
        items[i] = &numbers[i];
    }

    // Define a AVL
    avl_linked *source = avl_initialize();
    printf("empty: %s\n", BOOL_STR(avl_empty(source)));
    printf("full:  %s\n", BOOL_STR(avl_full(source)));
    printf("count: %d\n", avl_count(source));
    printf("Insert test values:\n");

    for(int i = 0; i < count; i++) {
        avl_insert(source, items[i]);
    }
    avl_print(source);
    printf("empty: %s\n", BOOL_STR(avl_empty(source)));
    printf("inorder:   {");
    data_ptr values[count];
    avl_inorder(source, values);

    for(int i = 0; i < avl_count(source); i++) {
        printf("%d, ", *values[i]);
    }
    printf("}\n");
    printf("valid: %s\n", avl_error_string(buffer, MAX_STRING, avl_valid(source)));

    // Create an invalid AVL - with a bad height
    avl_linked *bad = avl_initialize();
    avl_insert(bad, items[0]);
    avl_insert(bad, items[1]);
    int save_height = bad->root->height;
    bad->root->height = 1;
    printf("valid: %s\n", avl_error_string(buffer, MAX_STRING, avl_valid(bad)));
    // create an invalid AVL with misplaced child by swapping children of root
    bad->root->height = save_height;
    avl_node *temp = bad->root->right;
    bad->root->right = bad->root->left;
    bad->root->left = temp;
    printf("valid: %s\n", avl_error_string(buffer, MAX_STRING, avl_valid(bad)));
    // create an invalid AVL with bad balance
    bad = avl_initialize();
    avl_insert(bad, items[0]);
    avl_insert(bad, items[1]);
    avl_insert(bad, items[2]);
    bad->root->height = 3;
    bad->root->right->height = 2;
    bad->root->left->height = 1;
    bad->root->right->left = bad->root->left;
    bad->root->left = NULL;
    printf("valid: %s\n", avl_error_string(buffer, MAX_STRING, avl_valid(bad)));

    printf("Remove %d:\n", *items[0]);
    data_ptr item = items[0];
    avl_remove(source, item, item);
    printf("  removed: %d\n", *item);
    printf("inorder:  {");
    avl_inorder(source, values);

    for(int i = 0; i < avl_count(source); i++) {
        printf("%d, ", *values[i]);
    }
    printf("}\n");

    printf("Destroy the AVL\n");
    avl_free(&source);
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

    test_avl();

    return (EXIT_SUCCESS);
}
