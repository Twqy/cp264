/*
 * Author: Ryan Tran, 169069378, tran9378@mylaurier.ca
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "common.h"
#include "queue.h"

QUEUE infix_to_postfix(char *infixstr);

int evaluate_postfix(QUEUE queue);

int evaluate_infix(char *infixstr);

#endif