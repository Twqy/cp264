/*
 -------------------------------------------------------
 File:     expression_ptest.c
 About:    public test driver
 Author:   HBF
 Version:  2025-02-13
 -------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "expression.h"

char *tests[] = { "1+2", "(1+2*3)", "10-((3*4)+8)/4" };

void test_infix_to_postfix() {
	printf("------------------\n");
	printf("Test: infix_to_postfix\n\n");
	int n = sizeof tests / sizeof *tests;
	QUEUE q = { 0 };
	for (int i = 0; i < n; i++) {
		q = infix_to_postfix(tests[i]);
		printf("infix_to_postfix(%s): ", tests[i]);
		display(q.front);
		clean_queue(&q);
		printf("\n");
	}
	printf("\n");
}

void test_evaluate_postfix() {
	printf("------------------\n");
	printf("Test: evaluate_postfix\n\n");
	int n = sizeof tests / sizeof *tests;
	QUEUE q = { 0 };
	for (int i = 0; i < n; i++) {
		q = infix_to_postfix(tests[i]);
		printf("evaluate_postfix(");
		display(q.front);
		printf("): %d", evaluate_postfix(q));
		clean_queue(&q);
		printf("\n");
	}
	printf("\n");
}

void test_evaluate_infix() {
	printf("------------------\n");
	printf("Test: evaluate_infix\n\n");
	int n = sizeof tests / sizeof *tests;
	for (int i = 0; i < n; i++) {
		printf("evaluate_infix(%s): %d", tests[i], evaluate_infix(tests[i]));
		printf("\n");
	}
	printf("\n");
}

void interative_exprssion(char *expstr) {
	char infixstr[100];
	sscanf(expstr, "%s", infixstr);
	do { 
		printf("infix expression: %s\n", infixstr);
		QUEUE postfix_queue = infix_to_postfix(infixstr);
		if (postfix_queue.length != 0) { 
			printf("postfix expression:");
			display(postfix_queue.front);
			printf("\n");
			printf("postfix evaluation: %d\n", evaluate_postfix(postfix_queue));
			clean_queue(&postfix_queue);
			printf("infix evaluation: %d\n", evaluate_infix(infixstr));
		} else {
			printf("Invalid expression\n");
		}
		printf("enter an expression: e.g. (2+3)*2, or quit to exit\n");
		gets(infixstr);
		//fgets(infixstr, 100, stdin);
		if (strcmp(infixstr, "quit") == 0) break;

	} while(1);
}


int main(int argc, char *args[]) {
	if (argc <= 1) {
		test_infix_to_postfix();
		test_evaluate_postfix();
		test_evaluate_infix();
	} else {
		interative_exprssion(args[1]);
	}
	return 0;
}
