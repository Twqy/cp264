/*
 * Author:Ryan Tran, 169069378, tran9378@mylaurier.ca
 */
#include <stdio.h>
#include "stack.h"

void push(STACK *sp, NODE *np)
{
    // your code
    if (sp == NULL || np == NULL)
    {
        return;
    }

    if (sp->top == NULL)
    {
        sp->top = np;
        np->next = NULL;
    }
    else
    {
        np->next = sp->top;
        sp->top = np;
    }
    sp->length++;
}

NODE *pop(STACK *sp)
{
    // your code
    if (sp == NULL || sp->top == NULL)
    {
        return NULL;
    }
    NODE *temp = sp->top;

    sp->top = sp->top->next;
    temp->next = NULL;

    sp->length--;
    return temp;
}

void clean_stack(STACK *sp)
{
    clean(&(sp->top));
    sp->top = NULL;
    sp->length = 0;
}

// gcc common.c stack.c stack_ptest.c -o q1