/*
 * your program signature
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "common.h" // Must include common.h first for NODE definition

typedef struct queue
{
    NODE *front;
    NODE *rear;
    int length;
} QUEUE;

// Function prototypes
void enqueue(QUEUE *qp, NODE *np);
NODE *dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

#endif