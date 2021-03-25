#include "binary_trees.h"

/**
 * sorted_array_to_avl - inserts a sorted list into a avl
 * @array: is a pointer to the list
 * @size: is the size of the list
 * Return: head of the list
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int n, balance = 0;
	size_t i;
	avl_t *head = NULL, *ptr = NULL;

	for (i = 0; i < size; i++, array++)
	{
		n = *array;

		ptr = malloc(sizeof(avl_t));
		if (ptr == NULL)
			return (NULL);

		ptr->n = n;
		ptr->left = NULL;
		ptr->right = NULL;
		ptr->parent = NULL;

		if (head == NULL)
			head = ptr;
		else
		{
			balance = height(head->right, 0) - height(head->left, 0);
			if (i == size - 1 && !balance)
				balance = -100;

			head = create_avl(head, ptr, ptr->n, balance);
			if (balance != -100)
				head = fixer(ptr);
		}

	}
	return (head);
}


/**
 * create_avl - creates the avl tree
 * @head: head of the tree
 * @ptr: a spare pointer
 * @n: the number in the pointer
 * @bal: the balance number
 * Return: new head
 */
avl_t *create_avl(avl_t *head, avl_t *ptr, int n, int bal)
{
	avl_t *left = head->left, *right = head->right, *parent = head->parent;

	if (n > head->n)
	{
		if (right)
		{
			bal = bal == -100 ? -100 : height(head->right, 0) - height(head->left, 0);
			if (left && !bal)
			{
				if (parent)
				{
					if (parent->right == head)
						parent->right = ptr;
					if (parent->left == head)
						parent->left = ptr;
				}
				ptr->left = head;
				ptr->parent = head->parent;
				head->parent = ptr;
				return (ptr);
			}
			create_avl(right, ptr, n, bal);
		}
		else
		{
			head->right = ptr;
			ptr->parent = head;
		}
	}
	else if (n < head->n)
	{
		if (left)
			create_avl(left, ptr, n, bal);
		else
		{
			head->left = ptr;
			ptr->parent = head;
		}
	}
	return (head);
}

/**
 * height - gets the height
 * @top: the head of the tree
 * @hei: starting number
 * Return: balance number
 */
int height(avl_t *top, int hei)
{
	if (!top)
		return (0);

	hei += height(top->right, hei);
	hei += height(top->left, hei);
	hei += 1;

	return (hei);
}

/**
 * fixer - goes trough and makes changes to the tree from the bottom up
 * @point: point to start at
 * Return: the head
 */
avl_t *fixer(avl_t *point)
{
	avl_t *head = NULL;
	int balance = 0;

	while (point)
	{
		balance = height(point->right, 0) - height(point->left, 0);
		balancer(point, balance);
		if (!point->parent)
			head = point;
		point = point->parent;
	}
	return (head);

}

/**
 * balancer - balances the tree
 * @top: the top of the tree
 * @balance: the balance number
 * Return: the head
 */
avl_t *balancer(avl_t *top, int balance)
{
	avl_t *swap = NULL, *parent = NULL;

	if (balance > 0)
	{
		swap = top->right;
		parent = top->parent;

		top->left = swap->left;
		top->right = swap->right;
		top->parent = swap;

		swap->left = top;
		swap->right = NULL;
		if (parent)
		{
			if (parent->right == top)
				parent->right = swap;
			if (parent->left == top)
				parent->left = swap;
		}
		swap->parent = parent;

		top = swap;

		while (top->parent)
			top = top->parent;
		return (top);
	}
	return (top);
}
