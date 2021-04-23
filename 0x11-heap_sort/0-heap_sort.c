#include "sort.h"

/**
 * heapify - allows us to interact with our array as if it was a heap
 * @array: int array
 * @size: size of the part of the array you're manipulating
 * @i: largest point
 * @tsize: true size of the array
 * Return: void
 */
void heapify(int *array, int size, int i, int tsize)
{
	int li, ri, swap, large = i;

	li = i * 2 + 1;
	ri = i * 2 + 2;

	if (li < size && array[li] > array[large])
		large = li;
	if (ri < size && array[ri] > array[large])
		large = ri;
	if (large != i)
	{
		swap = array[large];
		array[large] = array[i];
		array[i] = swap;
		print_array(array, tsize);
		heapify(array, size, large, tsize);
	}
}


/**
 * heap_sort - heap sort alorithm
 * @array: the int array we are sorting
 * @size: size of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i, swap;

	if (!size || !array)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i > 0; i--)
	{
		if (array[0] >= array[i])
		{
			swap = array[0];
			array[0] = array[i];
			array[i] = swap;
			print_array(array, size);
		}
		heapify(array, i, 0, size);
	}
}
