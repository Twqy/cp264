/*
 * Author: Ryan Tran, 169069378, tran9378@mylaurier.ca
 */

#include <stdio.h>
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np)
{
    // your code
    if (qp == NULL || np == NULL)
    {
        return;
    }

    np->next = NULL;

    if (qp->front == NULL)
    {
        qp->front = np;
        qp->rear = np;
    }
    else
    {
        qp->rear->next = np;
        qp->rear = np;
    }
    qp->length++;
}

NODE *dequeue(QUEUE *qp)
{
    // your code
    if (qp == NULL || qp->front == NULL)
    {
        return NULL;
    }

    NODE *temp = qp->front;
    qp->front = qp->front->next;

    if (qp->front == NULL)
    {
        qp->rear = NULL;
    }

    temp->next = NULL;
    return temp;
}

void clean_queue(QUEUE *qp)
{
    clean(&(qp->front));
    qp->front = NULL;
    qp->rear = NULL;
    qp->length = 0;
}

// gcc common.c queue.c queue_ptest.c -o q1