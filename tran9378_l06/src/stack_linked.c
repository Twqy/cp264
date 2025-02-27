/**
 * -------------------------------------
 * @file  stack_linked.c
 * Linked Stack Source Code File
 * -------------------------------------
 * @author Ryan Tran, 169069378, tran9378@mylaurier.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
// Includes
#include "stack_linked.h"

//==================================================================================
// Functions

stack_linked *stack_initialize()
{
    // Allocate memory to the stack header
    stack_linked *source = malloc(sizeof *source);
    // Initialize the stack top
    source->top = NULL;
    return source;
}

void stack_free(stack_linked **source)
{
    stack_node *node = NULL;

    while ((*source)->top != NULL)
    {
        node = (*source)->top;
        (*source)->top = (*source)->top->next;
        data_free(&node->item);
        free(node);
    }
    // Free the stack header
    free(*source);
    *source = NULL;
    return;
}

bool stack_empty(const stack_linked *source)
{
    return (source->top == NULL);
}

bool stack_push(stack_linked *source, data_ptr item)
{
    // allocate memory to a new stack node
    stack_node *node = malloc(sizeof *node);
    // allocate memory for the data
    node->item = malloc(sizeof *node->item);
    // copy the data parameter to the new memory
    data_copy(node->item, item);
    // update the stack top
    node->next = source->top;
    source->top = node;
    return true;
}

bool stack_peek(const stack_linked *source, data_ptr item)
{
    bool peeked = false;

    if (source->top != NULL)
    {
        // return a copy of the data in the node
        data_copy(item, source->top->item);
        peeked = true;
    }
    return peeked;
}

bool stack_pop(stack_linked *source, data_ptr *item)
{
    bool popped = false;

    if (source->top != NULL)
    {
        // return a pointer to the node data
        *item = source->top->item;
        stack_node *temp = source->top;
        // update the stack top and free the removed node
        source->top = source->top->next;
        free(temp);
        popped = true;
    }
    return popped;
}

void stack_print(const stack_linked *source)
{
    char string[DATA_STRING_SIZE];
    stack_node *current = source->top;

    while (current != NULL)
    {
        data_string(string, sizeof string, current->item);
        printf("%s\n", string);
        current = current->next;
    }
}
