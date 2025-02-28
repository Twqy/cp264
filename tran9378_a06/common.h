/*--------------------------------------------------
 File:    common.h
 About:   node structure and functions for linked list queue and stack
 Author:  HBF
 Version: 2025-02-13
 --------------------------------------------------
 */ 
#ifndef COMMON_H
#define COMMON_H

/* 
 Node structure of linked list queue and stack for postfix expression operations
 int data - represent operand, operator, or parenthesis according to the type
 int type - 0:operand; 1:operator; 2:left parenthesis 3:right parenthesis
 */
typedef struct node {
	int data;
	int type;
	struct node *next;
} NODE;

NODE *new_node(int data, int type);
void clean(NODE **npp);
void display(NODE *np);
int mytype(char c);
int priority(char op);

#endif
