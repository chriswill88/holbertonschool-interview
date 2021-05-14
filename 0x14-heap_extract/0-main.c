#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/* Our own functions */
heap_t *_array_to_heap(int *array, size_t size);
void _binary_tree_delete(binary_tree_t *tree);
void binary_tree_print(const binary_tree_t *tree);

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	heap_t *root;
	int array[] = {
		98, 110, 43, 56, 2, 78, 123, 76, 234
	};
	size_t size = sizeof(array) / sizeof(array[0]);
	int value;

	root = _array_to_heap(array, size);
	binary_tree_print(root);

	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);

	_binary_tree_delete(root);
	return (0);
}