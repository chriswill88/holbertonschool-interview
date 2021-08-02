#include "binary_trees.h"
/**
 * height - returns the height of the binary tree
 * @tree: ptr to the tree
 * 
 * Return: the height of the tree.
 */
int height(binary_tree_t* tree) {
	if (tree == NULL)
		return (-1);
	else
		return max(height(tree->left), height(tree->right)) + 1;
}

/**
 * binary_tree_is_avl - checks if a tree is avl
 * @tree: tree head pointer
 * 
 * Return: 1 if true 0 if false
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (height(tree->right) - height(tree->left) > 1)
		return (0);
	return (1);
}