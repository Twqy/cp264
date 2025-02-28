/*
 -------------------------------------------------------
 File:     queue_ptest.c
 About:    public test driver
 Author:   HBF
 Version:  2025-02-13
 -------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h> 
#include "common.h"
#include "queue.h"

char tests[] = { '(', '2', '+', '3', ')' };
//char tests[] = {'(', '2', '+', '3', ')', '*', '(', '5', '-', '2', ')'};

void test_enqueue() {
	printf("------------------\n");
	printf("Test: enqueue\n\n");
	int n = sizeof tests / sizeof *tests;
	QUEUE q = { 0 };
	int data = 0;
	int type = -1;
	for (int i = 0; i < n; i++) {
		type = mytype(tests[i]);
		if (type == 0)
			data = tests[i] - '0';
		else
			data = tests[i];
		enqueue(&q, new_node(data, type));
		printf("enqueue(%c): ", tests[i]);
		display(q.front);
		printf("\n");
	}
	printf("enqueue length: %d", q.length);
	clean_queue(&q);
	printf("\n");
}

void test_dequeue() {
	printf("------------------\n");
	printf("Test: dequeue\n\n");
	int n = sizeof tests / sizeof *tests;
	QUEUE q = { 0 };
	int data = 0;
	int type = -1;
	for (int i = 0; i < n; i++) {
		type = mytype(tests[i]);
		if (type == 0)
			data = tests[i] - '0';
		else
			data = tests[i];
		enqueue(&q, new_node(data, type));
	}
	printf("enqueue: ");
	display(q.front);
	printf("\n");
	for (int i = 0; i < n; i++) {
		NODE *np = dequeue(&q);
		if (np->type == 0)
			printf("dequeue(%d): ", np->data);
		else
			printf("dequeue(%c): ", np->data);
		display(q.front);
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char* args[]) {
	if (argc <= 1) {
		test_enqueue();
		test_dequeue();
	} else {
		char str[100];
		printf("Enter math expression, i.e. 1+2*3\n");
		scanf("%s", str);

		// display an expression
		printf("enqueue:%s\n", str);
		// create a queue to store the infix expression
		QUEUE q = { 0 };
		int sign = 1;
		int num = 0;
		char *p = str;

		while (*p) {   // parse expression string to parts and store in queue
			if (*p == '-' && (p == str || *(p - 1) == '(')) { // determine negative sign
				sign = -1;
			} else if (*p >= '0' && *p <= '9') { // use Horner's algorithm to convert digits to int number
				num = *p - '0';
				while ((*(p + 1) >= '0' && *(p + 1) <= '9')) {
					num = num * 10 + *(p + 1) - '0';
					p++;
				}
				enqueue(&q, new_node(sign * num, 0)); // enqueue the signed number
				sign = 1;
			} else if (*p == '+' || *p == '-' || *p == '*' || *p == '/'
					|| *p == '%')
				enqueue(&q, new_node(*p, 1));   // enqueue operator
			else if (*p == '(')
				enqueue(&q, new_node(*p, 2));   // enqueue left parenthesis
			else if (*p == ')')
				enqueue(&q, new_node(*p, 3));   // enqueue right parenthesis

			p++;
		}

		printf("display queue:");
		display(q.front);
		printf("\nqueue length:%d\n", q.length);
		printf("dequeue:");
		NODE *np = NULL;
		while (q.front) {
			np = dequeue(&q);
			if (np->type == 0)
				printf("%d", np->data);
			else
				printf("%c", np->data);

			free(np);
			if (q.front)
				printf(" ");
		}

		clean_queue(&q);
		printf("\nqueue-length:%d\n", q.length);
	}
	return 0;
}
