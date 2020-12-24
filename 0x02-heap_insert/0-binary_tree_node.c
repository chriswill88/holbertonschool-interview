#include "binary_trees.h"
/**
 * binary_tree_node - creates binary tree node
 * @parent: binary tree node parent
 * @value: new value
 * Return: new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->right = NULL;
	new->left = NULL;

	return (new);
}
