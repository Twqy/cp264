/*
 * Author: Ryan Tran, 169069378, tran9378@mylaurier.ca
 */

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

QUEUE infix_to_postfix(char *infixstr)
{
    char *p = infixstr;
    QUEUE queue = {0};
    STACK stack = {0};
    int sign = 1, num = 0;

    while (*p)
    {
        if (*p == '-' && (p == infixstr || *(p - 1) == '('))
        {
            sign = -1;
        }

        else if (mytype(*p) == 0)
        {
            num = *p - '0';

            while ((*(p + 1) >= '0' && *(p + 1) <= '9'))
            {
                num = num * 10 + *(p + 1) - '0';
                p++;
            }

            enqueue(&queue, new_node(sign * num, 0));
            sign = 1;
        }

        else if (mytype(*p) == 1)
        {
            push(&stack, new_node(*p, 1));
        }

        else if (mytype(*p) == 2)
        {
            push(&stack, new_node(*p, 2));
        }

        else if (mytype(*p) == 3)
        {
            while (stack.top && stack.top->data != '(')
            {
                enqueue(&queue, pop(&stack));
            }
            pop(&stack);
        }

        p++;
    }

    while (stack.top)
    {
        enqueue(&queue, pop(&stack));
    }
    return queue;
}

int evaluate_postfix(QUEUE queue)
{
    NODE *p = queue.front;
    STACK stack = {0};
    int type = 0;

    while (p)
    {
        type = p->type;
        if (type == 0)
        {
            push(&stack, new_node(p->data, 0));
        }

        else if (type == 1)
        {
            int operator= p->data;
            NODE *oprand2 = pop(&stack);

            if (operator== '+')
            {
                stack.top->data = stack.top->data + oprand2->data;
            }

            else if (operator== '-')
            {
                stack.top->data = stack.top->data - oprand2->data;
            }

            else if (operator== '*')
            {
                stack.top->data = stack.top->data * oprand2->data;
            }

            else if (operator== '/')
            {
                stack.top->data = stack.top->data / oprand2->data;
            }

            free(oprand2);
        }
        p = p->next;
    }

    int result = stack.top->data;
    clean_stack(&stack);
    return result;
}

int evaluate_infix(char *infixstr)
{
    QUEUE queue = infix_to_postfix(infixstr);
    int result = evaluate_postfix(queue);
    return result;
}


// gcc common.c stack.c queue.c expression.c expression_ptest.c -o q1