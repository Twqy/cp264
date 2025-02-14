/*
--------------------------------------------------
Project: a4q1
File:    mysort_ptest.c 
About:   public test driver
Author:  HBF
Version: 2025-01-28
--------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mysort.h"

#define FLOATFORMAT "%.0f"
#define MAX_LEN 100

int cmp1(void *x, void *y) {
  float b = *(float*)x;
  float a = *(float*)y; 
	if (a > b) return 1;
	else if (a < b) return -1;
	else return 0;
}

void display_array(float *a[], int left, int right)
{
  int i;
  if (left<=right)
	  printf(FLOATFORMAT, *a[left]);
  if (left<right)
  for (i=left+1; i<=right; ++i) {
	printf(" ");
    printf(FLOATFORMAT, *a[i]);
  }
}

void copy_data_address(float d[], float *a[], int left, int right)
{
  int i;
  for (i = left; i <= right; i++)
    a[i] = &d[i];
}


static float test_data[MAX_LEN] ={
5,4,3,2,1,
3,1,4,1,5,
3, 1, 4, 5, 2, 7, 6, 9, 8, 0,
1,4,2,8,5,7
};

static int tests[][2] ={
{0,4},
{5,9},
{10,19},
{20,25}
};

void test_select_sort() {
	printf("------------------\n");
	printf("Test: select_sort\n\n");
	float *a[MAX_LEN];
	int count = sizeof tests / sizeof *tests;
	for (int i = 0; i < count; i++) {
		int left = tests[i][0];
		int right = tests[i][1];
		copy_data_address(test_data, a, left, right);
		printf("select_sort(");
		display_array(a, left, right);
		printf("): ");
		select_sort((void*) a, left, right);
		display_array(a, left, right);
		printf("\n");
	}
	printf("\n");
}

void test_quick_sort() {
	printf("------------------\n");
	printf("Test: quick_sort\n\n");
	float *a[MAX_LEN];
	int count = sizeof tests / sizeof *tests;
	for (int i = 0; i < count; i++) {
		int left = tests[i][0];
		int right = tests[i][1];
		copy_data_address(test_data, a, left, right);
		printf("quick_sort(");
		display_array(a, left, right);
		printf("): ");
		quick_sort((void*) a, left, right);
		display_array(a, left, right);
		printf("\n");
	}
	printf("\n");
}


void test_my_sort() {
	printf("------------------\n");
	printf("Test: my_sort\n\n");
	float *a[MAX_LEN];
	int count = sizeof tests / sizeof *tests;
	for (int i = 0; i < count; i++) {
		int left = tests[i][0];
		int right = tests[i][1];
		copy_data_address(test_data, a, left, right);
		printf("my_sort(");
		display_array(a, left, right);
		printf("): ");
		my_sort((void*) a, left, right, cmp1);
		display_array(a, left, right);
		printf("\n");
	}
	printf("\n");
}


void time_test_sort() {
	printf("------------------\n");
	printf("Test: sorting time and comparison\n\n");
	printf("Algorithm runtime testing:\n");
	float d[MAX_LEN];
	float *a[MAX_LEN];

//generate randomly an array of MAX_LEN elements
	srand(time(NULL));
	for (int i = 0; i < MAX_LEN; i++) {
		d[i] = rand() % MAX_LEN;
	}

//run time measuring for selection_sort
	int m1 = 100;
	clock_t t1 = clock();
	for (int i = 0; i < m1; i++) {
		copy_data_address(d, a, 0, MAX_LEN - 1);
		select_sort((void*) a, 0, MAX_LEN - 1);
	}
	clock_t t2 = clock();
	double time_span1 = (double) t2 - t1;
	printf("time_span(select_sort(%d numbers) for %d times)(ms):%0.1f\n", MAX_LEN,
			m1, time_span1);

//run time measuring for quick_sort
	int m2 = 1000;
	t1 = clock();
	for (int i = 0; i < m2; i++) {
		copy_data_address(d, a, 0, MAX_LEN - 1);
		quick_sort((void*) a, 0, MAX_LEN - 1);
	}
	t2 = clock();
	double time_span2 = (double) t2 - t1;
	printf("time_span(quick_sort(%d numbers) for %d times)(ms):%0.1f\n", MAX_LEN,
			m2, time_span2);

	printf(
			"time_span(select_sort(%d numbers))/time_span(quick_sort(%d numbers)):%0.1f\n",
			MAX_LEN, MAX_LEN, (time_span1 / 10) / (time_span2 / m2));
}


int main(int argc, char *args[])
{ 
	if (argc <= 1) {
	  test_select_sort();
	  test_quick_sort();
	  test_my_sort();
	} else {
		time_test_sort();
	}
	return 0;
} 
