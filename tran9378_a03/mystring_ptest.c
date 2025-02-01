/*
 --------------------------------------------------
 File:    mystring_ptest.c
 About:   public test driver
 Author:  HBF
 Version: 2025-01-21
 --------------------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include "mystring.h"

#define MAX_LINE 10
#define MAX_LINE_LEN 80
#define MAX_WORD

char tests[][80] = {
"Abc  DEF",
"  aBc   Def   ",
"Toonie is the Canadian $2 coin. ",
"Binary has 10 digits.  "
};

void test_str_words() {
	printf("------------------\n");
	printf("Test: str_words\n\n");
	int count = sizeof tests / sizeof *tests;
	for (int i = 0; i < count; i++)
		printf("str_words(%s):%d\n", tests[i], str_words(tests[i]));

	printf("\n");
}

void test_str_lower() {
	printf("------------------\n");
	printf("Test: str_lower\n\n");
	char dest[MAX_LINE_LEN];
	int count = sizeof tests / sizeof *tests;
	for (int i = 0; i < count; i++) {
		strcpy(dest, tests[i]);
		str_lower(dest);
		printf("str_lower(%s):%s\n", tests[i], dest);
	}
	printf("\n");
}

void test_str_trim() {
	printf("------------------\n");
	printf("Test: str_trim\n\n");
	char dest[MAX_LINE_LEN];
	int count = sizeof tests / sizeof *tests;
	for (int i = 0; i < count; i++) {
		strcpy(dest, tests[i]);
		str_trim(dest);
		printf("str_trim(%s):%s\n", tests[i], dest);
	}
	printf("\n");
}

int main(int argc, char* args[]) {
	test_str_words();
	test_str_lower();
	test_str_trim();	
	return 0;
}

