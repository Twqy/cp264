/**
 * -------------------------------------
 * @file  avl_linked.h
 * Linked AVL Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef AVL_LINKED_H_
#define AVL_LINKED_H_

// Includes87342q
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"

// typedefs
/**
 * AVL validation enum
 *
 * AVL_VALID - the AVL is valid
 * AVL_BAD_CHILDREN - the AVL violates the AVL rule in terms of parent/child values
 * AVL_HEIGHT_VIOLATION - the AVL violates the AVL rule in terms of parent/child heights
 * AVL_NOT_BALANCED - the AVL is not balanced
 */
typedef enum AVL_ERROR
{
    AVL_VALID,
    AVL_BAD_CHILDREN,
    AVL_HEIGHT_VIOLATION,
    AVL_NOT_BALANCED
} AVL_ERROR;

/**
 * AVL node
 */
typedef struct AVL_NODE
{
    data_ptr item;          // Pointer to the node data.
    int height;             // Height of the current node.
    struct AVL_NODE *left;  // Pointer to the left child.
    struct AVL_NODE *right; // Pointer to the right child.
} avl_node;

/**
 * AVL header
 */
typedef struct
{
    int count;      // Number of nodes in the AVL.
    avl_node *root; // Pointer to root node of the AVL.
} avl_linked;

// Prototypes

/**
 * Initializes a AVL.
 *
 * @return pointer to a AVL
 */
avl_linked *avl_initialize();

/**
 * Frees all parts of a AVL.
 *
 * @param source - pointer to a AVL
 */
void avl_free(avl_linked **source);

/**
 * Determines if a AVL is empty.
 *
 * @param source - pointer to a AVL
 * @return - true if the AVL is empty, false otherwise
 */
bool avl_empty(const avl_linked *source);

/**
 * Determines if a AVL is full.
 *
 * @param source - pointer to a AVL
 * @return - true if the AVL is full, false otherwise
 */
bool avl_full(const avl_linked *source);

/**
 * Returns number of items in a AVL.
 *
 * @param source - pointer to a AVL
 * @return - number of items in AVL
 */
int avl_count(const avl_linked *source);

/**
 * Inserts a copy of an item into a AVL.
 *
 * @param source - pointer to a AVL Pointer to a AVL.
 * @param item - pointer to the item to push
 * @return - true if item inserted, false otherwise
 */
bool avl_insert(avl_linked *source, const data_ptr item);

/**
 * Retrieves a copy of a value matching key in a AVL.
 *
 * @param source - pointer to a AVL
 * @param key - key value to search for
 * @param item - pointer to copy of the item retrieved
 * @return - true if item retrieved, false otherwise (key not found)
 */
bool avl_retrieve(const avl_linked *source, data_ptr key, data_ptr item);

/**
 * Removes a value matching key in a AVL.
 *
 * @param source - pointer to a AVL
 * @param key - key value to search for
 * @param item - pointer to the item removed
 * @return - true if item removed, false otherwise (key not found)
 */
bool avl_remove(avl_linked *source, const data_ptr key, data_ptr item);

/**
 * Copies source to target.
 *
 * @param target - pointer to a AVL
 * @param source - pointer to a AVL
 */
void avl_copy(avl_linked **target, const avl_linked *source);

/**
 * Copies the contents of a AVL to an array in inorder.
 *
 * @param source - pointer to a AVL
 * @param items - array of items: length must be at least size of AVL
 */
void avl_inorder(const avl_linked *source, data_ptr *items);

/**
 * Copies the contents of a AVL to an array in preorder.
 *
 * @param source - pointer to a AVL
 * @param items - array of items: length must be at least size of AVL
 */
void avl_preorder(const avl_linked *source, data_ptr *items);

/**
 * Copies the contents of a tree to an array in postorder.
 *
 * @param source - pointer to a AVL
 * @param items - array of items: length must be at least size of AVL
 */
void avl_postorder(const avl_linked *source, data_ptr *items);

/**
 * Finds the maximum item in a AVL.
 *
 * @param source - pointer to a AVL
 * @param item - pointer to copy of maximum item
 * @return - true if a maximum value is found, false otherwise (list is empty)
 */
bool avl_max(const avl_linked *source, data_ptr item);

/**
 * Finds the minimum item in a AVL.
 *
 * @param source - pointer to a AVL
 * @param item - pointer to copy of minimum item
 * @return - true if a minimum value is found, false otherwise (list is empty)
 */
bool avl_min(const avl_linked *source, data_ptr item);

/**
 * Finds the number of leaf nodes in a tree.
 *
 * @param source - pointer to a AVL
 * @return - count of nodes with no children.
 */
int avl_leaf_count(const avl_linked *source);

/**
 * Finds the number of nodes with one child in a tree.
 *
 * @param source - pointer to a AVL
 * @return - count of nodes with one child.
 */
int avl_one_child_count(const avl_linked *source);

/**
 * Finds the number of nodes with two children in a tree.
 *
 * @param source - pointer to a AVL
 * @return - count of nodes with two children
 */
int avl_two_child_count(const avl_linked *source);

/**
 * Determines the number of nodes with zero, one, and two children.
 * (May not call avl_leaf_count, avl_one_child_count, or avl_two_child_count.)
 *
 * @param source - pointer to a AVL
 * @param zero - count of leaf nodes (no children)
 * @param one - count of nodes with one child
 * @param two - count of nodes with two children
 */
void avl_node_counts(const avl_linked *source, int *zero, int *one, int *two);

/**
 * Determines whether or not source is a valid AVL.
 *
 * @param source - pointer to a AVL
 * @return - AVL_ERROR code
 */
AVL_ERROR avl_valid(const avl_linked *source);

/**
 * Determines if two trees contain same data in same configuration.
 *
 * @param target - pointer to a AVL
 * @param source - pointer to a AVL
 * @return - true if target is identical to source, false otherwise
 */
bool avl_equals(const avl_linked *target, const avl_linked *source);

/**
 * Returns a string version of an AVL error.
 *
 * @param string - destination string
 * @param size - maximum size of destination string
 * @param source - pointer to source data
 * @return - pointer to string
 */
char *avl_error_string(char *string, size_t size, AVL_ERROR error);

/**
 * Prints the items in a AVL in preorder.
 *
 * @param source - pointer to a AVL
 */
void avl_print(const avl_linked *source);

#endif /* AVL_LINKED_H_ */
