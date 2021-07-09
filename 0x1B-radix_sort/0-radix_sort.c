#include "sort.h"

void copyArr(int *array, int *ptr, size_t size)
{
    size_t i = 0;

    for (; i < size; i++)
        array[i] = ptr[i];
}

int maxer(int *array, size_t size)
{
    size_t i = 0;
    int max = 0;

    for (; i < size; i++)
        if (array[i] > max)
            max = array[i];

    return max;
}


int indexer(int ele, int index, int placer)
{
    return (ele % index) / placer;
}

void sort(int *array, int *ptr, int max, int index, int placer, size_t size)
{
    size_t i;
    int x = 0, y = 0;

    if (index > max * 10)
        return ;

    for (; x < 10; x++)
    {
        for (i = 0; i < size; i++)
        {
            if (x == indexer(array[i], index, placer))
            {
                ptr[y] = array[i];
                y++;
            }
        }
    }
    copyArr(array, ptr, size);
    print_array(array, size);

    sort(array, ptr, max, index * 10, placer * 10, size);
}

void radix_sort(int *array, size_t size)
{
    size_t i = 0;
    int max, *ptr;

    ptr = malloc(size * sizeof(int));
    if (ptr == NULL)
        return ;
    
    for (; i < size; i++)
        ptr[i] = 0;

    max = maxer(array, size);
    
    sort(array, ptr, max, 10, 1, size);
    free(ptr);
}