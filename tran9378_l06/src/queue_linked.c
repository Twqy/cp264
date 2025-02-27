/**
 * -------------------------------------
 * @file  queue_linked.c
 * Linked Queue Source Code File
 * -------------------------------------
 * @author Ryan Tran, 169069378, tran9378@mylaurier.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
// Includes
#include "queue_linked.h"

// Functions

queue_linked *queue_initialize() // works
{

    // your code here
    queue_linked *source = malloc(sizeof *source);
    source->front = NULL;
    source->rear = NULL;
    return source;
}

void queue_free(queue_linked **source) // works
{
    // your code here
    queue_node *node = NULL;

    while ((*source)->front != NULL)
    {
        node = (*source)->front;
        (*source)->front = (*source)->front->next;
        free(node);
    }
    free(*source);
    *source = NULL;
    return;
}

bool queue_empty(const queue_linked *source) // works
{

    // your code here
    return source->front == NULL;
}

int queue_count(const queue_linked *source) // works
{
    // your code here
    int count = 0;
    queue_node *node = source->front;
    while (node != NULL)
    {
        node = node->next;
        count++;
    }
    return count;
}

bool queue_insert(queue_linked *source, data_ptr item)
{
    queue_node *node = malloc(sizeof *node);
    node->item = malloc(sizeof *node->item);
    data_copy(node->item, item);

    if (source->count == 0)
    {
        source->front = node;
        source->rear = node;
    }
    else
    {
        source->rear->next = node;
        source->rear = node;
    }
    source->count++;
    return true;
}

bool queue_peek(const queue_linked *source, data_ptr item) // works
{

    // your code here
    if (source->front == NULL)
    {
        return false;
    }

    item = source->front->item;
    return true;
}

bool queue_remove(queue_linked *source, data_ptr *item)
{
    if (source->front == NULL)
    {
        return false;
    }

    queue_node *temp = source->front;
    *item = temp->item;

    source->front = source->front->next;
    if (source->front == NULL)
    {
        source->rear = NULL;
    }

    free(temp);
    source->count--;

    return true;
}

void queue_print(const queue_linked *source)
{
    char string[DATA_STRING_SIZE];
    queue_node *current = source->front;

    while (current != NULL)
    {
        data_string(string, sizeof string, current->item);
        printf("%s\n", string);
        current = current->next;
    }
    return;
}
