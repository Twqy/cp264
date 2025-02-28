/*--------------------------------------------------
 File:     common.c
 About:    implementation of common.h
 Author:   HBF
 Version:  2025-02-13
 --------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

NODE *new_node(int data, int type) {
	NODE *np = (NODE *) malloc(sizeof(NODE));
	np->data = data;
	np->type = type;
	np->next = NULL;
	return np;
}

void clean(NODE **npp) {
	NODE *tmp, *np = *npp;
	while (np) {
		tmp = np;
		np = np->next;
		free(tmp);
	}
	*npp = NULL;
}

void display(NODE *np) {
	while (np) {
		if (np->type == 0)
			printf("%d", np->data);
		else
			printf("%c", np->data);

		np = np->next;

		if (np)
			printf(" ");
	}
}

int mytype(char c) {
	int t = -1;
	if (c >= '0' && c <= '9')
		t = 0;
	else if (c == '+' || c == '-' || c == '*' || c == '/')
		t = 1;
	else if (c == '(')
		t = 2;
	else if (c == ')')
		t = 3;
	else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		t = 4;
	else if (c == ' ')
	    t = 5;

	return t;
}

int priority(char op) {
	int r = -1;
	if (op == '/' || op == '*' || op == '%')
		r = 1;
	else if (op == '+' || op == '-')
		r = 0;

	return r;
}
