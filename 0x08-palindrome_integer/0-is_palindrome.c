#include "palindrome.h"
/**
 * is_palindrome - recognizes a palindrome from an unsigned long int
 * @n: the long int in question
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(unsigned long n)
{
	int a[20] = {0}, r = 0, i = 0, x = 0;

	while (n)
		r = n % 10, n /= 10, a[i++] = r;


	while (i--)
	{
		if (a[i] != a[x])
			return (0);
		if (x > i)
			break;
		x++;
	}
	return (1);
}
