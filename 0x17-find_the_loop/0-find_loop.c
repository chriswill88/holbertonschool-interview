#include "lists.h"

/**
 * find_listint_loop - finds the beginning of the loop;
 * @head: pointer the the beginning
 * Return: NULL or pointer the start of the loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *skip, *ptr;

	if (!head || !head->next || !head->next->next)
		return (NULL);

	if (head == head->next)
		return (head);
	if (head->next->next == head)
		return (head);

	ptr = head;
	skip = head->next->next;

	for (; skip && ptr; skip = skip->next->next, ptr = ptr->next)
		if (ptr == skip)
			break;

	if (skip && ptr)
		for (; head; head = head->next)
		{
			ptr = ptr->next;
			for (; ptr != skip; ptr = ptr->next)
			{
				if (ptr == head)
					return (head);
			}
		}

	return (NULL);
}
