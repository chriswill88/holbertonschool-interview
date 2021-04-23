#ifndef __SORT__
#define __SORT__

#include <stdlib.h>
#include <stdio.h>

void heapify(int *array, int size, int i, int tsize);
void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);


#endif
