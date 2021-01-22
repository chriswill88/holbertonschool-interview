#include "lists.h"

/**
 * lener - gets the length
 * @head: the linked list
 * Return: the length of the lists
 */
int lener(listint_t *head)
{
	listint_t *pF = head;
	int len = 0;

	for (; pF->next; pF = pF->next, len++)
		;
	return (len);
}
/**
 * arrayform - changes the array to suit the algorithm
 * @head: the end of the linked list
 * @len1: the length of the change
 * Return: the end of the array
 */
listint_t *arrayform(listint_t *head, int len1)
{
	listint_t *pF = head, *pA = head, *pB = head;
	int half = len1 % 2 ? len1 / 2 : len1 / 2 + 1;

	for (pF = head; len1 && pF; len1--)
	{
		if (len1 + 1 < half)
		{
			pA = pF->next;
			pF->next = pB;
			pB = pF;
			pF = pA;
		}
		else
		{
			pB = pF;
			pF = pF->next;
		}
	}
	pF->next = pB;
	return (pF);
}
/**
 * list_corrector - corrects the linked list.
 * @end: the end of the linked list
 * @len1: the length of the change
 * Return: nothing
 */
void list_corrector(listint_t *end, int len1)
{
	listint_t *ptr = end, *prev = NULL, *next = end;

	len1 = len1 ? len1 : 1;
	for (; len1; len1--)
	{
		next = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = next;
	}
}

/**
 * is_palindrome - checks for palindrome
 * @head: the singly linked list
 * Return: 1 if list is palindrome else 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *end, *beg, *fixend;
	int len1 = 0, half = 0;

	if (!head)
		return (0);
	if (!*head)
		return (1);
	beg = *head, end = *head;
	if (!beg->next)
		return (1);

	len1 = lener(*head);
	half = len1 % 2 ? len1 / 2 : len1 / 2 + 1;
	end = arrayform(*head, len1);
	fixend = end;
	while (half-- && beg != end)
	{
		if (end->n != beg->n)
		{
			list_corrector(fixend, len1 % 2 ? len1 / 2 : len1 / 2 + 1);
			return (0);
		}
		end = end->next;
		beg = beg->next;
	}
	half = len1 % 2 ? len1 / 2 : len1 / 2 + 1;
	list_corrector(fixend, half);
	return (1);
}
