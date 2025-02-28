/*
 * Author: Ryan Tran, 169069378, tran9378@mylaurier.ca
 */
#ifndef STACK_H
#define STACK_H
#include "common.h"

typedef struct stack
{
    int length;
    NODE *top;
} STACK;

void push(STACK *sp, NODE *np);
NODE *pop(STACK *sp);
void clean_stack(STACK *sp);

#endif