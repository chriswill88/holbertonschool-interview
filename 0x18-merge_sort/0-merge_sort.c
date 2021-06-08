#include "sort.h"

void working_sort(int *array, size_t subset) {
    printf("subset size %ld\n", subset);

    if (subset > 1)
        working_sort(array, subset/2);

}


/**
 * merge_sort - 
 * 
 * 
 */
void merge_sort(int *array, size_t size)
{
    int *workarray = malloc(size);

    printf("Start merge sort\n");
    free(workarray);

    working_sort(array, size);
}