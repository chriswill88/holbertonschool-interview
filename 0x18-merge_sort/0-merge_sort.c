#include "sort.h"


/**
 * printArray - prints segments of the array
 * @A: array
 * @iBegin: start index
 * @iEnd: end index
 *
 * Return: void
 */
void printArray(int A[], size_t iBegin, size_t iEnd)
{
	for (; iBegin < iEnd; iBegin++)
	{
		printf("%d", A[iBegin]);
		if (iBegin < iEnd - 1)
			printf(", ");
	}
}


/**
 * TopDownMerge - sorts the segments of the array and merges them
 * @B: working array
 * @iBegin: start index
 * @iMiddle: middle index
 * @iEnd: end index
 * @A: array
 *
 * Return: void
 */
void TopDownMerge(int A[], size_t iBegin, size_t iMiddle, size_t iEnd, int B[])
{
	size_t i = iBegin, j = iMiddle;

	printf("[left]: ");
	printArray(B, iBegin, iMiddle);
	printf("\n");

	printf("[right]: ");
	printArray(B, iMiddle, iEnd);
	printf("\n");

	for (size_t k = iBegin; k < iEnd; k++)
	{
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j]))
		{
			B[k] = A[i];
			i = i + 1;
		}
		else
		{
			B[k] = A[j];
			j = j + 1;
		}
	}
	printf("[Done]: ");
	printArray(B, iBegin, iEnd);
	printf("\n");
}


/**
 * TopDownSplitMerge - this function recursivly splits the array then merges
 * @B: working array
 * @iBegin: start index
 * @iEnd: end index
 * @A: array
 *
 * Return: void
 */
void TopDownSplitMerge(int B[], size_t iBegin, size_t iEnd, int A[])
{
	if (iEnd - iBegin <= 1)
		return;
	size_t iMiddle = (iEnd + iBegin) / 2;

	TopDownSplitMerge(A, iBegin,  iMiddle, B);
	TopDownSplitMerge(A, iMiddle,    iEnd, B);
	printf("Merging...\n");
	TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}


/**
 * TopDownMergeSort - copies the array into a working buffer, starts the algo
 * @A: is the array
 * @B: is the working array
 * @n: is that size of the array
 *
 * Return: void
 */
void TopDownMergeSort(int A[], int B[], size_t n)
{
	for (size_t k = 0; k < n; k++)
		B[k] = A[k];

	TopDownSplitMerge(B, 0, n, A);
}


/**
 * merge_sort - sorts an array using the merge sort algorithm
 * @array: the array we will sort
 * @size: the size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *workarray = malloc(size);

	if (!workarray)
		return;

	TopDownMergeSort(array, workarray, size);
	free(workarray);
}
