#ifndef __SPRC__
#define __SPRC__

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void printArray(int A[], size_t iBegin, size_t iEnd);
void TopDownMerge(int A[], size_t iBegin, size_t iMid, size_t iEnd, int B[]);
void TopDownSplitMerge(int B[], size_t iBegin, size_t iEnd, int A[]);
void TopDownMergeSort(int A[], int B[], size_t n);

#endif
