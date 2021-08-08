#include "binary_trees.h"


int is_sort(binary_tree_t *head, binary_tree_t *node)
{
  int hval, nval = node->n;

  if (head == NULL)
    return (0);
  hval = head->n;

  if (hval == nval)
    return (1);
 
  return (nval > hval ? is_sort(head->right, node) : is_sort(head->left, node));
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
 * @tree: ptr to the tree
 *
 * Return: the height of the tree.
 */
int height(binary_tree_t *tree, binary_tree_t* head)
{
  if (tree && !is_sort(head, tree))
  {
    return (100000);
  }
	return (!tree ? 0 : (max(height(tree->left, head), height(tree->right, head)) + 1));
}

/**
 * binary_tree_is_avl - checks if a tree is avl
 * @tree: tree head pointer
 *
 * Return: 1 if true 0 if false
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	return ((!tree || (height(tree->right, (binary_tree_t *)tree) - height(tree->left, (binary_tree_t *)tree)) > 0) ? 0 : 1);
}
