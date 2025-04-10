/*--------------------------------------------------
 File:    bigint_ptest.c
 About:   public test driver
 Author:  HBF
 Version: 2025-02-04
 --------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"
#include "bigint.h"

char *oprs1[] = { "111", "2222", "666666666666", "1111111111111111111" };
char *oprs2[] = { "222", "3333", "333333333334", "8888888888888888889" };
int tests[] = { 1, 2, 3, 10, 40, 100 };

void display_bigint(BIGINT bignumber) {
	NODE *ptr = bignumber.start;
	while (ptr != NULL) {
		printf("%d", ptr->data);
		ptr = ptr->next;
	}
}

void test_bigint() {
	printf("------------------\n");
	printf("Test: bigint\n\n");
	int n = sizeof oprs1 / sizeof *oprs1;
	BIGINT num = { 0 };
	for (int i = 0; i < n; i++) {
		printf("bigint(%s): ", oprs1[i]);
		num = bigint(oprs1[i]);
		display_bigint(num);
		printf("\n");
		dll_clean(&num);
	}
	printf("\n");
}

void test_bigint_add() {
	printf("------------------\n");
	printf("Test: bigint_add\n\n");
	int n = sizeof oprs1 / sizeof *oprs1;
	BIGINT a = { 0 }, b = { 0 }, c = { 0 };
	for (int i = 0; i < n; i++) {
		printf("%s+%s:", oprs1[i], oprs2[i]);
		a = bigint(oprs1[i]);
		b = bigint(oprs2[i]);
		c = bigint_add(a, b);
		display_bigint(c);
		printf("\n");
		dll_clean(&a);
		dll_clean(&b);
		dll_clean(&c);
	}
	printf("\n");
}

void test_bigint_fibonacci() {
	printf("------------------\n");
	printf("Test: big_fibonacci\n\n");
	int n = sizeof tests / sizeof *tests;
	BIGINT f = { 0 };
	for (int i = 0; i < n; i++) {
		printf("bigint_fibonacci(%d): ", tests[i]);
		f = bigint_fibonacci(tests[i]);
		display_bigint(f);
		printf("\n");
		dll_clean(&f);
	}
	printf("\n");
}

int main(int argc, char* args[]) {
	if (argc <= 1) {
		test_bigint();
		test_bigint_add();
		test_bigint_fibonacci();
	} else {
		if (argc == 2) {
			int n = atoi(args[1]);
			printf("\nbigint_fibonacci(%d):", n);
			BIGINT s = bigint_fibonacci(n);
			display_bigint(s);
			printf("\ndigit count:%d", s.length);
			dll_clean(&s);
		} else if (argc == 3) {
			char *opr1 = args[2];
			char *opr2 = args[3];
			BIGINT a = bigint(opr1);
			BIGINT b = bigint(opr2);
			BIGINT s = bigint_add(a, b);
			display_bigint(a);
			printf("%c", '+');
			display_bigint(b);
			printf("=");
			display_bigint(s);
			dll_clean(&a);
			dll_clean(&b);
			dll_clean(&s);
		}
	}
	return 0;
}
