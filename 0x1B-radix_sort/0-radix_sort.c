#include "sort.h"

/**
 * copyArr - copy array
 *
 * @array: the array
 * @ptr: the array to copy
 * @size: the size of the array
 * Return: Void
 */
void copyArr(int *array, int *ptr, size_t size)
{
	size_t i = 0;

	for (; i < size; i++)
		array[i] = ptr[i];
}

/**
 * maxer - gets the max
 *
 * @array: the array
 * @size: the size of the array
 * Return: Void
 */
int maxer(int *array, size_t size)
{
	size_t i = 0;
	int max = 0;

	for (; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * indexer - spliter function
 *
 * @ele: the element from the array
 * @placer: the placer
 * @index: the index
 * Return: Void
 */
int indexer(int ele, int index, int placer)
{
	return ((ele % index) / placer);
}

/**
 * sort - sorts the array
 *
 * @array: the array
 * @ptr: the manipulated pointer
 * @max: the max
 * @index: the index
 * @placer: the placer
 * @size: the size of the array
 * Return: Void
 */
void sort(int *array, int *ptr, int max, int index, int placer, size_t size)
{
	size_t i;
	int x = 0, y = 0;

	if (index > max * 10)
		return;

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

/**
 * radix_sort - sorts the array
 *
 * @array: the array
 * @size: size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	size_t i = 0;
	int max, *ptr;

	if (!array)
		return;

	ptr = malloc(size * sizeof(int));
	if (ptr == NULL)
		return;

	for (; i < size; i++)
		ptr[i] = 0;

	max = maxer(array, size);

	sort(array, ptr, max, 10, 1, size);
	free(ptr);
}
