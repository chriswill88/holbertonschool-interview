#include "search.h"

/**
 * len - returns length of the list
 * @list: pointer to the head of the list
 * Return: the length
 */
int len(skiplist_t *list)
{
	skiplist_t *ptr = list;
	int len = 0;

	while (ptr->next)
	{
		ptr = ptr->next;
		len += 1;
	}
	return (len);
}

/**
 * linear_skip - finds value in a linked list with an express lane
 * @list: pointer to linked list
 * @value: value were searching for
 * Return: NULL or ptr with value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t cur_ind = 0, fut_ind = 0;
	int found_area = 0;
	skiplist_t *ptr = list, *future;

	while (ptr)
	{
		cur_ind = ptr->index;
		if (ptr->express && !found_area)
		{
			future = ptr->express;
			fut_ind = future->index;
			printf("Value checked at index [%ld] = [%d]\n", fut_ind, future->n);
			if (future->n >= value)
			{
				printf("Value found between indexes [%ld] and [%ld]\n", cur_ind, fut_ind);
				found_area = 1;
			}
			else
				ptr = future;
		}
		else
		{
			if (found_area == 0)
			{
				fut_ind = len(list);
				printf("Value found between indexes [%ld] and [%ld]\n", cur_ind, fut_ind);
				found_area = 1;
			}
			printf("Value checked at index [%ld] = [%d]\n", cur_ind, ptr->n);
			if (ptr->n == value)
				return (ptr);

			ptr = ptr->next;
		}
	}
	return (NULL);
}
