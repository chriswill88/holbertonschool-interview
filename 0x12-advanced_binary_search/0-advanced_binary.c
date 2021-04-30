#include "search_algos.h"

/**
 * line_print - this function prints the array we are searching in
 * @beg: the index of the beginning of the list we are searching in
 * @end: the index of the end of the list
 * @arr: the array
 * Return: void
 */
void line_print(int beg, int end, int *arr)
{
	printf("Searching in array: ");
	while (beg <= end)
	{
		printf("%d", arr[beg++]);
		if (beg != end + 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * search_recur - recursion binary search
 * @beg: the index of the beginning
 * @end: the index of the end
 * @value: the value to find
 * @array: the int array
 * @size: the size of the array
 * Return: the index of the found value in the array
 */
int search_recur(int beg, int end, int value, int *array, int size)
{
	int midind = beg + (end - beg) / 2, mid = array[midind], incl = end - beg;

	line_print(beg, end, array);

	if (array[beg] == value)
		return (beg);
	if (incl != 0)
	{
		if (value > mid)
			beg = midind + 1;
		else
			end = midind;
		return (search_recur(beg, end, value, array, size));
	}

	return (-1);
}


/**
 * advanced_binary - this function finds the first value of in the search.
 * @array: the int array
 * @size: the size of the array
 * @value: the value to find
 * Return: the index in the array
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (search_recur(0, size - 1, value, array, size));
}
