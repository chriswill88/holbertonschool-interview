#include "list.h"

/**
 * insert - inserts the node
 * @head: head ptr
 * @ptr: ptr
 * @new: new ptr
 *
 * Return: void
 */
void insert(List *head, List *ptr, List *new)
{
	new->next = head;
	new->prev = ptr;

	head->prev = new;
	ptr->next = new;
}

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: double linked list
 * @str: string
 *
 * Return: new node
 */
List *add_node_end(List **list, char *str)
{
	List *start = *list, *ptr = NULL, *new = NULL;

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->str = strdup(str);

	if (start == NULL)
	{
		*list = new;
		new->prev = new;
		new->next = new;
		return (new);
	}
	ptr = start->prev;

	insert(start, ptr, new);
	return (new);
}

/**
 * add_node_end - Add a new node to the beginning of a circular linked list
 * @list: double linked list
 * @str: string
 *
 * Return: new node
 */
List *add_node_begin(List **list, char *str)
{
	List *start = *list, *ptr = NULL, *new = NULL;

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);
	new->str = strdup(str);

	if (start == NULL)
	{
		*list = new;
		new->prev = new;
		new->next = new;
		return (new);
	}
	ptr = start->prev;

	insert(start, ptr, new);
	*list = new;
	return (new);
}
