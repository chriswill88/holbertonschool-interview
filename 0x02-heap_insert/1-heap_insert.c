#include "binary_trees.h"

/**
 * switch_nodes - switches nodes
 * @great: the node with the bigger value
 * @less: the node with smaller value
 * Return: nothing
 */
void switch_nodes(heap_t **great, heap_t **less)
{
	heap_t *l_parent, *temp;

	/* switching prev parents pararent child node to great*/
	if ((*less)->parent)
	{
		l_parent = (*less)->parent;
		if (l_parent->right == (*less))
			l_parent->right = (*great);
		else
			l_parent->left = (*great);
	}
	/* switch the parents of the child nodes for the left and right*/
	if ((*less)->left && (*less)->left != (*great))
		(*less)->left->parent = (*great);
	if ((*less)->right && (*less)->right != (*great))
		(*less)->right->parent = (*great);
	if ((*great)->left)
		(*great)->left->parent = (*less);
	if ((*great)->right)
		(*great)->right->parent = (*less);
	/* swich node parents*/
	(*great)->parent = (*less)->parent;
	(*less)->parent = (*great);
	/* switch nodes child nodes*/
	if ((*less)->left == (*great))
	{
		(*less)->left = (*great)->left;
		(*great)->left = (*less);
		temp = (*less)->right;
		(*less)->right = (*great)->right;
		(*great)->right = temp;
	}
	else
	{
		(*less)->right = (*great)->right;
		(*great)->right = (*less);
		temp = (*less)->left;
		(*less)->left = (*great)->left;
		(*great)->left = temp;
	}
}

/**
 * swap - swaps two pointers that a double pointer was pointing to
 * @one: pointer to a pointer to an item;
 * @two: pointer to a pointer to an item;
 * Return: nothing
 */
void swap(heap_t **one, heap_t **two)
{
	heap_t *temp;

	temp = *one;
	*one = *two;
	*two = temp;
}


/**
 * fix - after nodes are set the fix max heap sorts the tree
 * @s: the tree
 * @start: a pointer to a node on the tree;
 * Return: a number so it know weather to continue to sort or not.
 */
int fix(heap_t **s, heap_t *start)
{
	heap_t *left = start->left, *right = start->right;
	int value = 0;

	if (left && right)
	{
		value += fix(s, left);
		value += fix(s, right);
		if (left->n > right->n)
		{
			if (left->n > start->n)
			{
				value = 1;
				switch_nodes(&left, &start);
				swap(&start, &left);
				if (start->parent == NULL)
					*s = start;
			}
		} else
			if (right->n > start->n)
			{
				value = 1;
				switch_nodes(&right, &start);
				swap(&start, &right);
				if (start->parent == NULL)
					*s = start;
			}
	}
	else if (left)
	{
		value += fix(s, left);
		if (left->n > start->n)
		{
			value = 1;
			switch_nodes(&left, &start);
			swap(&start, &left);
			if (start->parent == NULL)
				*s = start;
		}
	}
	return (value);
}

/**
 * inserted - inserts a created node into a binary tree;
 * @start: a node in the binary tree
 * @new: the new node
 * @max: max level of the tree
 * @n: level mover
 * Return: New Node or Null
 */
int inserted(heap_t *start, heap_t *new, int max, int n)
{
	int lv = 0, rv = 0, v = 0;

	if (n < max)
	{
		if (start->left && start->right)
		{
			lv = inserted(start->left, new, max, n + 1);
			if (!lv)
				rv = inserted(start->right, new, max, n + 1);
		}

		if (!start->left)
		{
			start->left = new;
			new->parent = start;
			return (1);
		}
		else if (!start->right)
		{
			start->right = new;
			new->parent = start;
			return (1);
		}
	}
	else
		return (0);
	v = lv + rv;
	return (v);
}


/**
 * heap_insert - creates binary tree node with max heap sort
 * @root: binary tree node parent
 * @value: new value
 * Return: new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *find = *root;
	int v = 1;
	int max = 0;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->right = NULL;
	new->left = NULL;

	if (!*root)
	{
		new->parent = NULL;
		*root = new;
	}
	else
	{
		while (find->left)
		{
			find = find->left;
			max++;
		}
		if (!inserted(*root, new, max, 0))
		{
			while (find->left)
				find = find->left;
			find->left = new;
			new->parent = find;
		}
	}
	do
		v = fix(root, *root);
	while (v == 1);

	return (new);
}
