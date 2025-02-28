/*
 -------------------------------------------------------
 Project:  cp264-a6q2
 File:     stack_ptest.c
 About:    public test driver
 Author:   HBF
 Version:  2025-02-13
 -------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h> 
#include "common.h" 
#include "stack.h"

char tests[] = { '1', '2', '+', '3', 'a' };
//char tests[] = {'(', '2', '+', '3', ')', '*', '(', '5', '-', '2', ')'};

void test_push() {
	printf("------------------\n");
	printf("Test: push\n\n");
	int n = sizeof tests / sizeof *tests;
	STACK sk = { 0 };
	int data = 0;
	int type = -1;
	for (int i = 0; i < n; i++) {
		type = mytype(tests[i]);
		if (type == 0)
			data = tests[i] - '0';
		else
			data = tests[i];
		push(&sk, new_node(data, type));
		printf("push(%c): ", tests[i]);
		display(sk.top);
		printf("\n");
	}
	printf("stack length: %d", sk.length);
	clean_stack(&sk);
	printf("\n");
}

void test_pop() {
	printf("------------------\n");
	printf("Test: pop\n\n");
	int n = sizeof tests / sizeof *tests;
	STACK sk = { 0 };
	int data = 0;
	int type = -1;
	for (int i = 0; i < n; i++) {
		type = mytype(tests[i]);
		if (type == 0)
			data = tests[i] - '0';
		else
			data = tests[i];
		push(&sk, new_node(data, type));
	}
	printf("stack: ");
	display(sk.top);
	printf("\n");
	for (int i = 0; i < n; i++) {
		NODE *np = pop(&sk);
		if (np->type == 0)
			printf("pop(%d): ", np->data);
		else
			printf("pop(%c): ", np->data);
		display(sk.top);
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char* args[]) {
	if (argc <= 1) {
		test_push();
		test_pop();
	} else {

		char *str = "12 34 56 78 90 + - * /";

		printf("str:%s\n", str);

		// parse
		STACK stack = { 0 };
		int sign = 1;
		int num = 0;
		char *p = str;

		while (*p) {  // parse space separated string and push into stack
			if (*p == '-' && (p == str || *(p - 1) == ' ')) { // determine negative sign
				sign = -1;
			} else if (*p >= '0' && *p <= '9') {
				num = *p - '0';
				while ((*(p + 1) >= '0' && *(p + 1) <= '9')) {
					num = num * 10 + *(p + 1) - '0';
					p++;
				}
				push(&stack, new_node(num, 0));
				sign = 1;
			} else if (*p == '+' || *p == '-' || *p == '*' || *p == '/'
					|| *p == '%')
				push(&stack, new_node(*p, 1));
			else if (*p == '(')
				push(&stack, new_node(*p, 2));
			else if (*p == ')')
				push(&stack, new_node(*p, 3));
			else
				;  // ignore
			p++;
		}

		printf("display stack:");
		display(stack.top);
		printf("\nstack height:%d\n", stack.length);

		printf("pop:");
		NODE *np = NULL;
		while (stack.top) {
			np = pop(&stack);
			if (np->type == 0)
				printf("%d", np->data);
			else
				printf("%c", np->data);
			free(np);
			if (stack.top)
				printf(" ");
		}

		clean_stack(&stack);
		printf("\nstack-height:%d\n", stack.length);

	}
	return 0;
}

