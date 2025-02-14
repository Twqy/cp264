/*
 * @author ryan tran, 169069378, tran9378@mylaurier.ca
 * @file mysort.h
 */ 

#ifndef MYSORT_H
#define MYSORT_H 

// your code document
void select_sort(void *a[], int left, int right);

// your code document
void quick_sort(void *a[], int left, int right);

// your code document
void my_sort(void *a[], int left, int right, int (*cmp)(void*, void*) );

#endif