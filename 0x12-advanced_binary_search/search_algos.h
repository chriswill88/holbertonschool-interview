#ifndef __SEARCH__
#define __SEARCH__

#include <stdio.h>

void line_print(int beg, int end, int *arr);
int search_recur(int beg, int end, int value, int *array, int size);
int advanced_binary(int *array, size_t size, int value);

#endif /* !__SEARCH__*/
