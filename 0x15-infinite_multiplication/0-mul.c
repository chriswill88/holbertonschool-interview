#include "holberton.h"


/**
 * isChars - checks that strings are all char digits
 * @str: a string
 *
 * Return: 1 or 0
 */
int isChars(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (1);
	return (0);
}

/**
 * zerocut - truncates the zero from the beggining of the string
 * @str: a string
 *
 * Return: the truncated string
 */
char *zerocut(char *str)
{
	static char arr[50000];
	char *sec = arr;
	int len, i = 0, x = 0, on = 0;

	for (len = 0; str[len]; len++)
		;
	while (i < len)
	{
		if (str[i] != 0 && str[i] != '0')
			on = 1;
		if (on)
			arr[x++] = str[i];
		i++;
	}
	return (sec);
}

/**
 * add - add two char strings together
 *
 * @a: a string of numbers
 * @b: a string of numbers
 * Return: a string of the sum of a and b
 */
char *add(char *a, char *b)
{
	int len = 0, i, len_a = 0, len_b = 0, hold = 0, result;
	int inta, intb, put, x;
	static char tot[50000], tmp[50000];
	char *ret;

	if (b == NULL || *b == '\0')
	{
		ret = tot;
		for (i = 0; a[i] != '\0'; i++)
			tot[i] = a[i];
		return (ret);
	}
	for (len_a = 0; a[len_a]; len_a++)
		;
	for (len_b = 0; b[len_b]; len_b++)
		;
	len = len_a > len_b ? len_a + 1 : len_b + 1;
	ret = tmp;
	for (i = 0; i < len; i++)
		ret[i] = '0';
	for (i = len, x = len; i; i--, x--)
	{
		len_a--;
		len_b--;
		inta = (a[len_a] && len_a >= 0 ? a[len_a] : '0') - '0';
		intb = (b[len_b] && len_b >= 0 ? b[len_b] : '0') - '0';
		result = inta + intb + hold;
		put = result % 10;
		ret[i] = '0' + (put);
		if (result > 9)
			hold = result / 10;
		else
			hold = 0;
	}
	return (ret);
}

/**
 * mul - multiplies two number strings
 *
 * @place: the place of zeros
 * @num: the number to multiply by
 * @single: number to multiply by
 * Return: the product
 */
char *mul(int place, char *num, int single)
{
	int len = 0, i = 0, hold = 0, put, result, x;
	static char arr[50000];
	char *ptr = arr;

	for (len = 0; num[len]; len++)
		;
	for (i = 0; i < place + len + 1; i++)
		arr[i] = '0';
	for (i = 0, x = len; i < len; i++, x--)
	{
		result = single * (num[x - 1] - '0') + hold;
		put = result % 10;
		arr[x] = '0' + (put);
		if (result > 9)
			hold = result / 10;
		else
			hold = 0;
	}
	arr[x] = '0' + hold;
	return (ptr);
}

/**
 * main - this function multiplies infinite numbers
 *
 * @argc: number of string
 * @argv: the string
 * Return: 98 if fail and 0 if not
 */
int main(int argc, char *argv[])
{
	static char totarr[50000], resarr[50000];
	char *mul1, *mul2, *res, *tot = NULL, *err = "Error";
	unsigned int i = 0, len1, len2, x, y, swap = 0;

	if (argc != 3 || (isChars(argv[1]) || (isChars(argv[2]))))
	{
		for (i = 0; err[i]; _putchar(err[i++]))
			;
		_putchar('\n');
		return (98);
	}
	for (i = 0; totarr[i]; i++)
		totarr[i] = '0';
	for (len1 = 0; argv[1][len1]; len1++)
		;
	for (len2 = 0; argv[2][len2]; len2++)
		;
	mul1 = len1 > len2 ? argv[1] : argv[2];
	mul2 = mul1 == argv[1] ? argv[2] : argv[1];
	if (len1 < len2)
		swap = len1, len1 = len2, len2 = swap;
	for (i = 0, x = len2 - 1; i < len2; i++, x--)
	{
		res = mul(i, mul1, mul2[x] - '0'), res = zerocut(res);
		for (y = 0; res[y]; y++)
			resarr[y] = res[y];
		res = resarr;
		tot = add(res, tot);
		tot = zerocut(tot);
		for (y = 0; tot[y]; y++)
			totarr[y] = tot[y];
		tot = totarr;
	}
	if (tot[0] == 0)
		_putchar('0');
	else
		for (i = 0; tot[i]; _putchar(tot[i++]))
			;
	_putchar('\n');
	return (0);
}
