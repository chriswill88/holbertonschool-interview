#include "binary_trees.h"

/**
 * is_sort - checks if the node is in the right place
 *
 * @head: head of the tree
 * @n: node to check for
 * @f: bool - found node vaule
 * Return: 0 || 1
 */
int is_sort(binary_tree_t *head, binary_tree_t *n, int f)
{
	int hval, nval = n->n;
	binary_tree_t *grand;

	if (head == NULL)
	{
		if (f)
			return (1);
		return (0);
	}

	if (head->parent->parent)
	{
		grand = head->parent->parent;
		if (!grand->left || !grand->right)
			return (0);
	}

	hval = head->n;

	if (hval == nval)
	{
		if (f)
			return (0);
		f = 1;
	}

	return (nval > hval ? is_sort(head->right, n, f) : is_sort(head->left, n, f));
}

/**
 * max - returns the greater of two numbers
 *
 * @num1: a number
 * @num2: a number
 * Return: the max
 */
int max(int num1, int num2)
{
	return (num1 > num2 ? num1 : num2);
}

/**
 * height - returns the height of the binary tree
 *
 * @tree: ptr to the tree
 * @h: head of the tree
 *
 * Return: the height of the tree.
 */
int height(binary_tree_t *tree, binary_tree_t *h)
{
	if (tree && !is_sort(h, tree, 0))
	{
		printf("Not sorted\n");
		return (9999999);
	}
	return (!tree ? 0 : (max(height(tree->left, h), height(tree->right, h)) + 1));
}

/**
 * binary_tree_is_avl - checks if a tree is avl
 * @tree: tree head pointer
 *
 * Return: 1 if true 0 if false
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	binary_tree_t *h = (binary_tree_t *)tree;

	if (!tree)
		return (0);

	return (((height(tree->right, h) - height(tree->left, h)) > 1) ? 0 : 1);
}
