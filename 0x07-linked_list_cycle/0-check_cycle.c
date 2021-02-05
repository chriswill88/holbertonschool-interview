#include "lists.h"

/**
 * check_cycle - checks for cycle in linked list
 * @list: linked list
 * Return: 1 or 0
 */
int check_cycle(listint_t *list)
{
	listint_t *ptr1, *ptr2;

	if (!list)
		return (0);
		ptr2 = ptr1 = list;

	while (ptr1 && ptr2)
	{
		if (!ptr1->next || !ptr2->next || !ptr2->next->next)
			return (0);
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
		if (ptr1 == ptr2)
			return (1);
	}
	return (0);
}
