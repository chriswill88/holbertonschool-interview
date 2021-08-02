#ifndef __LOL__
#define __LOL__

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s avl_t;
int binary_tree_is_avl(const binary_tree_t *);
static int print_t(const binary_tree_t *tree, int, int, char **);
static size_t _height(const binary_tree_t *);
void binary_tree_print(const binary_tree_t *);


#endif
