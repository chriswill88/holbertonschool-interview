#include "binary_trees.h"

/**
 * extract - moves root to the end for extraction
 * @rt: root node
 * Return: void
 */
heap_t *extract(heap_t *rt)
{
	heap_t *r = rt->right ? rt->right : NULL, *l = rt->left ? rt->left : NULL;
	heap_t *s = NULL, *sp = NULL;
	int swap;

	if (l && r)
		s = (l->n >= r->n) ? l : r;
	else if (l || r)
		s = l ? l : r;
	else
		return (rt);

	swap = s->n;
	s->n = rt->n;
	rt->n = swap;

	sp = s;
	s = rt;
	rt = sp;

	return (extract(rt));
}

/**
 * remover - removes a node from the bin tree
 * @ptr: is the node to remove
 * Return: void
 */
void remover(heap_t *ptr)
{
	heap_t *l, *p = ptr->parent ? ptr->parent : NULL;

	if (ptr->parent)
	{
		l = p->left ? p->left : NULL;
		if (l && l == ptr)
			p->left = NULL;
		else
			p->right = NULL;
	}

	free(ptr);
}

/**
 * find_right - finds the next place on the bin tree to remove
 * @root: the root or starting node
 * @depth: the depth of the tree for use
 * @target_depth: the max depth of the bin tree
 * Return: the next node to remove
 */
heap_t *find_right(heap_t *root, int depth, int target_depth)
{
	heap_t *r = root->right ? root->right : NULL;
	heap_t *l = root->left ? root->left : NULL, *p = root;

	if (target_depth == 0)
		return (root);
	if (depth == target_depth)
	{
		if (r)
			return (r);
		else if (l)
			return (l);
		return (NULL);
	}
	else if (l && r)
	{
		p = find_right(r, depth + 1, target_depth);
		if (p == NULL)
			p = find_right(l, depth + 1, target_depth);
	}
	else
		return (NULL);
	return (p);
}

/**
 * swaper - swaps two nodes
 * @ptr1: is a node
 * @ptr2: is another node
 * Return: void
 */
void swaper(heap_t *ptr1, heap_t *ptr2)
{
	heap_t *p1 = ptr1->parent ? ptr1->parent : NULL;
	heap_t *p2 = ptr2->parent ? ptr2->parent : NULL;

	if (p1)
	{
		if (p1->left == ptr1)
			p1->left = ptr2;
		else
			p1->right = ptr2;
	}
	if (p2)
	{
		if (p2->left == ptr2)
			p2->left = ptr1;
		else
			p2->right = ptr1;
	}
	ptr1->parent = p2;
	ptr2->parent = p1;
}

/**
 * heap_extract - extracts the root node out of the binary tree
 * @root: this is the root node
 * Return: the value of the root node extracted
 */
int heap_extract(heap_t **root)
{
	int hold, depth = 0;
	heap_t *r = *root, *swap, *ld;


	if (!root || !(*root))
		return (0);
	hold = (*root)->n;
	r = extract(r);
	for (; (*root)->parent; *root = (*root)->parent)
		;
	for (ld = *root; ld->left; ld = ld->left, depth += 1)
		;
	swap = find_right(*root, 1, depth);
	if (r != swap)
		swaper(swap, r);
	if (!depth)
		*root = NULL;
	remover(r);

	return (hold);
}
