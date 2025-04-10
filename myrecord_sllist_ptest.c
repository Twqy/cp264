/*
 --------------------------------------------------
 File:    myrecord_llist_ptest.c
 About:   public test driver
 Author:  HBF
 Version: 2025-02-04
 --------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "myrecord_sllist.h"

char infilename[40] = "marks.txt";
char outfilename[40] = "record_report.txt";
char *stats_format = "%-10s%-6.1f\n";

RECORD tests[] = { { "A1", 10 }, { "A2", 20 }, { "A3", 30 }, { "A4", 40 }, {
		"A5", 50 }, { "A6", 60 }, { "A7", 70 }, { "A8", 80 }, { "A9", 90 }, {
		"A10", 100 } };
char *delete_items[] = { "A2", "A4", "A6", "A8" };
char *search_items[] = { "A1", "A3", "A5", "B" };

void sll_display(SLL *sllp, int type);

void test_ssl_insert() {
	printf("------------------\n");
	printf("Test: ssl_insert\n\n");
	int n = sizeof(tests) / sizeof(RECORD);
	SLL sllist = { 0 };
	printf("given linked list:");
	sll_display(&sllist, 0);
	printf("\n");
	for (int i = n - 2; i >= n / 2; i--) {
		printf("sll_insert(%s %0.1f): ", tests[i].name, tests[i].score);
		sll_insert(&sllist, tests[i].name, tests[i].score);
		sll_display(&sllist, 0);
		printf("\n");
	}
	printf("\n");
}

void test_ssl_delete() {
	printf("------------------\n");
	printf("Test: ssl_delete\n\n");
	int n = sizeof(tests) / sizeof(RECORD);
	SLL sllist = { 0 };
	for (int i = 0; i < n - 1; i++) {
		sll_insert(&sllist, tests[i].name, tests[i].score);
	}
	n = sizeof delete_items / sizeof *delete_items;
	printf("given linked list:");
	sll_display(&sllist, 0);
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("sll_delete(%s): ", delete_items[i]);
		sll_delete(&sllist, delete_items[i]);
		sll_display(&sllist, 0);
		printf("\n");
	}
	printf("\n");
}

void test_ssl_search() {
	printf("------------------\n");
	printf("Test: ssl_search\n\n");
	int n = sizeof(tests) / sizeof(RECORD);
	SLL sllist = { 0 };
	for (int i = 0; i < n; i++) {
		sll_insert(&sllist, tests[i].name, tests[i].score);
	}
	printf("given linked list:");
	sll_display(&sllist, 0);
	printf("\n");
	n = sizeof search_items / sizeof *search_items;
	NODE *np = NULL;
	for (int i = 0; i < n; i++) {
		np = sll_search(&sllist, search_items[i]);
		if (np != NULL)
			printf("sll_search(%s): %s %.1f\n", search_items[i], np->data.name,
					np->data.score);
		else
			printf("sll_search(%s): not found\n", search_items[i]);
	}
	printf("\n");
}

void test_record_data_file();

int main(int argc, char* args[]) {
	if (argc <= 1) {
		test_ssl_insert();
		test_ssl_search();
		test_ssl_delete();
	} else {
		if (argc >= 2)
			strcpy(infilename, args[1]);
		if (argc >= 3)
		   strcpy(outfilename, args[2]);

		test_record_data_file();
	}
	return 0;
}

/*
 * The following are the testing of record data file processing
 */

typedef struct {
	int count;
	float mean;
	float stddev;
	float median;
} STATS;

typedef struct {
	char letter_grade[3];
} GRADE;




GRADE grade(float score);
int import_data(FILE *fp, SLL *sllp);
STATS process_data(SLL *sllp);
int report_data(FILE *fp, SLL *sllp, STATS stats);


GRADE grade(float score) {
	char g[][5] = { "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+",
			"D", "D-", "F" };
	float b[] = { 100, 90, 85, 80, 77, 73, 70, 67, 63, 60, 57, 53, 50, 0 };
	GRADE r = { "F" };
	int i, n = sizeof(b) / sizeof(float);
	for (i = 0; i < n; i++) {
		if (score >= b[i + 1])
			break;
	}
	strcpy(r.letter_grade, g[i]);
	return r;
}

void test_record_data_file() {
	printf("------------------\n");
	printf("Test: record_data_file\n\n");
	printf("Test: import_data\n\n");
	SLL sllist = { 0 };
	FILE *fp = fopen(infilename, "r");
	if (fp == NULL) {
		perror("Error no file\n");
		return;
	}
	import_data(fp, &sllist);
	fclose(fp);
	sll_display(&sllist, 1);

	printf("\nTest: process_data\n\n");
	STATS stats = process_data(&sllist);
	printf(stats_format, "count", (float) stats.count);
	printf(stats_format, "mean", stats.mean);
	printf(stats_format, "stddev", stats.stddev);
	printf(stats_format, "median", stats.median);
	printf("\n");

	printf("\nTest: report_data\n\n");
	fp = fopen(outfilename, "w");
	report_data(fp, &sllist, stats);
	fclose(fp);

	fp = fopen(outfilename, "r");
	if (fp == NULL) {
		perror("Error no file.\n");
		return;
	}
	char line[100];
	while (fgets(line, sizeof(line), fp) != NULL) {
		printf("%s", line);
	}
	fclose(fp);

	printf("\nend of record_data_file test\n");

}

void swap(void **x, void **y) {
	void *temp = *y;
	*y = *x;
	*x = temp;
}

int cmp_inc(void *x, void *y) {
	RECORD *p1 = (RECORD*) x;
	RECORD *p2 = (RECORD*) y;
	float a = p1->score;
	float b = p2->score;
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}

int cmp_dec(void *x, void *y) {
	RECORD *p2 = (RECORD*) x;
	RECORD *p1 = (RECORD*) y;
	float a = p1->score;
	float b = p2->score;
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}

void my_sort(void *a[], int left, int right, int (*cmp)(void *, void*)) {
	for (int i = left; i <= right; ++i) {
		int k = i;
		for (int j = i + 1; j <= right; ++j) {
			if (cmp(a[j], a[k]) < 0) {
				k = j;
			}
		}
		if (i != k) {
			swap(&a[k], &a[i]);
		}
	}
}

int import_data(FILE *fp, SLL *sllp) {
	char line[40], name[40];
	float score = 0;
	while (fgets(line, sizeof(line), fp) != NULL) {
		if (sscanf(line, "%[^,],%f", name, &score) >= 2)
			sll_insert(sllp, name, score);
	}
	return sllp->length;
}

STATS process_data(SLL *sllp) {
	int i = 0, count = 0, n = sllp->length;
	float mean = 0;
	float stddev = 0;
	NODE *np = sllp->start;
	RECORD *a[n];
	while (np) {
		count++;
		mean += np->data.score;
		stddev += np->data.score * np->data.score;
		a[i] = &(np->data);
		np = np->next;
		i++;
	}
	mean /= count;
	stddev = sqrt(stddev / count - mean * mean);
	// prepare return value
	STATS stats = { };
	stats.count = count;
	stats.mean = mean;
	stats.stddev = stddev;
	// compute median
	my_sort((void*) a, 0, n - 1, cmp_inc);
	stats.median =
			(n % 2 == 1) ?
					a[n / 2]->score :
					(a[n / 2 - 1]->score + a[n / 2]->score) / 2;
	return stats;
}

int report_data(FILE *fp, SLL *sllp, STATS stats) {
	int n = stats.count;
	if (n < 1)
		return 0;
	char *stats_format = "%s:%.1f\n";
	fprintf(fp, "%s\n", "stats:value");
	fprintf(fp, "%s:%d\n", "count", stats.count);
	fprintf(fp, stats_format, "mean", stats.mean);
	fprintf(fp, stats_format, "stddev", stats.stddev);
	fprintf(fp, stats_format, "median", stats.median);

	RECORD *a[n];
	NODE *p = sllp->start;
	int i = 0;
	while (p) {
		a[i] = &(p->data);
		p = p->next;
		i++;
	}
	my_sort((void*) a, 0, n - 1, cmp_dec);

	char *file_format = "%s:%.1f,%s\n";
	fprintf(fp, "\n%s\n", "name:score,grade");
	for (i = 0; i < n; i++) {
		fprintf(fp, file_format, a[i]->name, a[i]->score,
				grade(a[i]->score).letter_grade);
	}
	return 1;
}


void sll_display(SLL *sllp, int type) {
	NODE *np = sllp->start;
	if (type == 1) {
		while (np != NULL) {
			printf("%s,%.1f\n", np->data.name, np->data.score);
			np = np->next;
		}
	}
	else {
		printf("length %d ", sllp->length);
		while (np != NULL) {
			printf("%s %.1f ", np->data.name, np->data.score);
			np = np->next;
		}
	}
}


