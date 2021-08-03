#include "binary_trees.h"

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
 * @tree: ptr to the tree
 *
 * Return: the height of the tree.
 */
int height(binary_tree_t *tree)
{
	binary_tree_t *t = tree;

	return (t == NULL ? -1 : (max(height(t->left), height(t->right)) + 1));
}

/**
 * binary_tree_is_avl - checks if a tree is avl
 * @tree: tree head pointer
 *
 * Return: 1 if true 0 if false
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	binary_tree_t *t = tree;

	return (t == NULL || (height(t->right) - height(t->left) > 1) ? 0 : 1);
}
