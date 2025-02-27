/**
 * -------------------------------------
 * @file  queue_linked.h
 * Linked Queue Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef QUEUE_LINKED_H_
#define QUEUE_LINKED_H_

// Includes
#include <stdio.h>
#include <stdlib.h>

#include "data.h"

// typedefs

/**
 * Queue node.
 */
typedef struct QUEUE_NODE {
    data_ptr item;            // Pointer to the node data.
    struct QUEUE_NODE *next;  // Pointer to the next queue node.
} queue_node;

/**
 * Queue header.
 */
typedef struct {
    queue_node *front;   // Pointer to the front node of the queue.
    queue_node *rear;    // Pointer to the rear node of the queue.
    int count;           // Number of items in queue.
} queue_linked;

// Prototypes

/**
 * Initializes a queue.
 *
 * @return - pointer to a new queue
 */
queue_linked* queue_initialize();

/**
 * Frees queue memory.
 *
 * @param source - pointer to a queue
 */
void queue_free(queue_linked **source);

/**
 * Determines if a queue is empty.
 *
 * @param source - pointer to a queue
 * @return - true if source is empty, false otherwise
 */
bool queue_empty(const queue_linked *source);

/**
 * Determines if a queue is full.
 *
 * @param source - pointer to source
 * @return - true if source is full, false otherwise
 */
bool queue_full(const queue_linked *source);

/**
 * Returns the number of items in a queue.
 *
 * @param source - pointer to a queue
 * @return - the number of items in source
 */
int queue_count(const queue_linked *source);

/**
 * Pushes a copy of an item onto a queue.
 *
 * @param source - pointer to a queue
 * @param item - pointer to the item to insert
 */
bool queue_insert(queue_linked *source, data_ptr item);

/**
 * Returns a copy of the item on the front of a queue, queue is unchanged.
 *
 * @param source - pointer to a queue
 * @param item - pointer to a copy of the item to retrieve
 * @return - true if item peeked, false otherwise (queue is empty)
 */
bool queue_peek(const queue_linked *source, data_ptr item);

/**
 * Removes and returns the item on the front of a queue.
 *
 * @param source - pointer to a queue
 * @param item - pointer the item to remove
 * @return - true if item removed, false otherwise (queue is empty)
 */
bool queue_remove(queue_linked *source, data_ptr *item);

/**
 * Prints the items in a queue from front to rear.
 * (For testing only).
 *
 * @param source - pointer to a queue
 */
void queue_print(const queue_linked *source);

#endif /* QUEUE_LINKED_H_ */
