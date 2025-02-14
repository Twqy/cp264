/*
 --------------------------------------------------
 Project: a4q2
 File:    myrecord_ptest.c
 About:   public test driver
 Author:  HBF
 Version: 2025-01-28
 --------------------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"

#define MAX_REC 100
#define MAX_LINE_LEN 100

char infilename[40] = "marks.txt";            //default input file name
char outfilename[40] = "record_report.txt";   //default output file name
char *stats_title = "Stats     value\n";
char *stats_format = "%-10s%-6.1f\n";
char *data_title = "\nname      score %%     grade\n";
char *data_format = "%-10s%-6.1f\n";

float grade_tests[] = {45.7, 50, 55, 59, 61, 63, 67.2, 72, 76, 79, 80.5, 85, 93.6};

void test_grade() {
	printf("------------------\n");
	printf("Test: grade\n\n");

	int count = sizeof(grade_tests) / sizeof *grade_tests;

	for (int i = 0; i < count; i++) {
		printf("grade(%.1f): %s\n", grade_tests[i],
				grade(grade_tests[i]).letter_grade);
	}
	printf("\n");
}

void test_import_data() {
	printf("------------------\n");
	printf("Test: import_data\n\n");

	RECORD dataset[MAX_REC]; // declare array of RECORD to store record data
	FILE *fp = fopen(infilename, "r");
	int count = import_data(fp, dataset);
	fclose(fp);
	printf("import_data():%d\n", count);
	if (count > 0) {
		for (int i = 0; i < count; i++) {
			printf(data_format, dataset[i].name, dataset[i].score);
		}
	}
	printf("\n");
}

void test_process_data() {
	printf("------------------\n");
	printf("Test: process_data\n\n");
	RECORD dataset[MAX_REC]; // declare array of RECORD to store record data
	
	FILE *fp = fopen(infilename, "r");
	if (fp == NULL) {
		perror("open input file error");
		return;
	}	
	int count = import_data(fp, dataset);
	fclose(fp);
	if (count > 0) {
		STATS stats = process_data(dataset, count);
		printf("%-10s%-6d\n", "count", stats.count);
		printf(stats_format, "mean", stats.mean);
		printf(stats_format, "stddev", stats.stddev);
		printf(stats_format, "median", stats.median);
	}
	printf("\n");
}

void test_report_data() {
	printf("------------------\n");
	printf("Test: report_data\n\n");
	RECORD dataset[MAX_REC]; // declare array of RECORD to store record data
	FILE *fp = fopen(infilename, "r");
	if (fp == NULL) {
		perror("open input file error");
		return;
	}
	int count = import_data(fp, dataset);
	fclose(fp);

	if (count > 0) {
		fp = fopen(outfilename, "w");
		if (fp == NULL) {
			perror("Error while opening the file.\n");
			return;
		}
		STATS stats = process_data(dataset, count);
		report_data(fp, dataset, stats);
		fclose(fp);
	}

	fp = fopen(outfilename, "r");
	if (fp == NULL) {
		perror("Error while opening the file.\n");
		return;
	}
	char line[MAX_LINE_LEN];
	while (fgets(line, sizeof(line), fp) != NULL) {
		printf("%s", line);
	}
	fclose(fp);
	printf("\n");
}

int main(int argc, char *args[]) {
	test_grade();
	test_import_data();
	test_process_data();
	test_report_data();
	return 0;
}
