#ifndef __DEFY__
#define __DEFY__

#include <stdio.h>
#include <stdlib.h>

void copyArr(int *array, int *ptr, size_t size);
int maxer(int *array, size_t size);
int indexer(int ele, int index, int placer);
void sort(int *array, int *ptr, int max, int index, int placer, size_t size);
void radix_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif
