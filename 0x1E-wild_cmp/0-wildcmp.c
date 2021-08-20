#include "holberton.h"

/**
 * recursive - recusivly iterate through strings
 *
 * @s1: string 1
 * @s2: string 2
 * @ind1: ind 1
 * @ind2: ind 2
 * @same: is it the same so far
 * @ns: before the wildcard
 *
 * Return: 0 or 1
 */
int recursive(char *s1, char *s2, int ind1, int ind2, int same, int ns)
{
	if (s2[ind2] == '*')
		return (recursive(s1, s2, ind1, ind2 + 1, same, ns));
	if ((s1[ind1] == '\0' || s2[ind2] == '\0') && s2[ind2] != '*')
	{
		if (!s2[ind2] && s2[ind2 - 1] == '*' && same)
			return (1);
		if (!(s1[ind1] == '\0' && s2[ind2] == '\0'))
			return (0);
		if (same)
			return (1);
		return (0);
	}
	if (s1[ind1] != s2[ind2])
	{
		if (ind2 >= 0 && s2[ind2 - 1] == '*')
		{
			ns = ind2;
			return (recursive(s1, s2, ind1 + 1, ind2, same, ns));
		}
		same = 0;
		return (recursive(s1, s2, ind1 + 1, ns, same, ns));
	}
	same = 1;
	return (recursive(s1, s2, ind1 + 1, ind2 + 1, same, ns));
}

/**
 * wildcmp - wild compare
 *
 * @s1: string
 * @s2: stirng with wild characters
 *
 * Return: 0 || 1
 */
int wildcmp(char *s1, char *s2)
{
	return (recursive(s1, s2, 0, 0, 1, 0));
}
