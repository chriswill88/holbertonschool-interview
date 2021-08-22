#include "substring.h"

/**
 * reset - resets arrays
 *
 * @found: array to reset
 * @size: size of array
 *
 * Return: void
 */
void reset(int *found, int size)
{
	int x = 0;

	for (; x < size; found[x] = 0, x++)
		;
}

/**
 * donecheck - checks if array is all 1
 *
 * @found: the found words - represented by indicies
 * @nb_words: number of words
 *
 * Return: 1 or 0
 */
int donecheck(int *found, int nb_words)
{
	int x = 0;

	for (; x < nb_words; x++)
	{
		if (found[x] == 0)
			return (0);
	}

	return (1);
}

/**
 * string_cmp - compares part of string to the array of words
 * @w: list of words
 * @s: string
 * @b: index of string
 * @f: the found words - represented by indexs
 * @n: number of words
 * @l: length of substrings
 *
 * Return: 1 or 0
 */
int string_cmp(char const **w, char const *s, int b, int f[100], int n, int l)
{
	int i = 0, x, fail;

	for (; i < n; i++)
	{
		fail = 1;
		for (x = 0; x < l; x++)
		{
			if (s[b + x] != w[i][x])
			{
				fail = 0;
				continue;
			}
		}
		if (f[i] == 0 && fail)
		{
			f[i] = 1;
			return (1);
		}
	}
	return (0);
}


/**
 * processer - processes the string
 *
 * @s: string
 * @i: index
 * @w: list of words
 * @n_w: number of words
 * @len_w: length of words
 * @f: holds the indicies found
 *
 * Return: 1 if f at that indicies
 */
int processer(char const *s, int i, char const **w, int n_w, int len_w, int *f)
{
	while (i < n_w)
	{
		if (string_cmp(w, s, i, f, n_w, len_w))
			i += len_w;
		else
			return (0);

		if (donecheck(f, n_w))
			return (1);
	}
	return (0);
}

/**
 * find_substring - a function that finds
 * all the possible substrings containing
 * a list of words, within a given string.
 *
 * @s: string
 * @words: list of words
 * @nb_words: number of words
 * @n: return number of indicies
 *
 * Return: array of ints
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int ind = 0, len = 0, i = 0;
	static int found[100];
	int *f = found, *r;

	*n = 0;

	for (; words[0][len] != '\0'; len++)
		;

	r = malloc(100 * sizeof(int));
	if (r == NULL)
		return (NULL);

	reset(r, 100);

	for (; s[ind]; ind++)
	{
		reset(f, 100);
		if (processer(s, ind, words, nb_words, len, f))
		{
			*n = i + 1;
			r[i] = ind;
			i++;
		}
	}

	return (r);
}
