/**
 * -------------------------------------
 * @file  stack_linked.h
 * Linked Stack Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef STACK_LINKED_H_
#define STACK_LINKED_H_

// Includes
#include <stdio.h>
#include <stdlib.h>

#include "data.h"

// typedefs

/**
 * Stack node.
 */
typedef struct STACK_NODE {
    data_ptr item;            // Pointer to the node data
    struct STACK_NODE *next; // Pointer to the next stack node
} stack_node;

/**
 * Stack header.
 */
typedef struct {
    stack_node *top;   // Pointer to the top node of the stack
} stack_linked;

// Prototypes

/**
 * Initializes a stack.
 *
 * @return - pointer to a stack
 */
stack_linked* stack_initialize();

/**
 * Frees stack memory. Frees all node and data memory.
 *
 * @param source - pointer to a stack
 */
void stack_free(stack_linked **source);

/**
 * Determines if a stack is empty.
 *
 * @param source - pointer to a stack.
 * @return - TRUE if source is empty, FALSE otherwise
 */
bool stack_empty(const stack_linked *source);

/**
 * Pushes a copy of an item onto a stack.
 *
 * @param source - pointer to a stack
 * @param item - pointer to the item to push
 */
bool stack_push(stack_linked *source, data_ptr item);

/**
 * Returns a copy of the item on the top of a stack, stack is unchanged.
 *
 * @param source - pointer to a stack
 * @param item - pointer to a copy of the retrieved item
 * @return - TRUE if item peeked, FALSE otherwise (stack is empty)
 */
bool stack_peek(const stack_linked *source, data_ptr item);

/**
 * Removes and returns a pointer to the item on the top of a stack.
 *
 * @param source - pointer to a stack
 * @param item - pointer the item to remove
 * @return - TRUE if item popped, FALSE otherwise (stack is empty)
 */
bool stack_pop(stack_linked *source, data_ptr *item);

/**
 * Prints the items in a stack from top to bottom. (For testing only).
 *
 * @param source - pointer to a stack
 */
void stack_print(const stack_linked *source);

#endif /* STACK_LINKED_H_ */
