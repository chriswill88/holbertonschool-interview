#include "lists.h"

/**
 * insert_node - inserts a node in a singly linked list
 * @head: pointer to the singly list
 * @number: number in new list
 * Return: new node or NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *ptr;

	if (!head)
		return (NULL);

	ptr = *head;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = number;

	if (!*head)
	{
		*head = new;
		return (new);
	}

	if (ptr->n < number)
	{
		while (ptr->next)
		{
			if (ptr->next->n > number)
				break;
			ptr = ptr->next;
		}
		new->next = ptr->next;
		ptr->next = new;
	}
	else
	{
		new->next = ptr;
		*head = new;
	}
	return (new);
}
