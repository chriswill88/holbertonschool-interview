#include "regex.h"



/**
 * astrix - astrix handeler
 *
 * @constant: char from pattern
 * @strdex: string index
 * @string: string
 *
 * Return: the new strdex
 */
int astrix(char constant, int strdex, char const *string)
{
	for (; (string[strdex] == constant || constant == '.')
	 && string[strdex]; strdex++)
	;
	return (strdex);
}


/**
 * len - gets the length of a string
 *
 * @str: string
 *
 * Return: length
 */
int len(char const *str)
{
	int length;

	for (length = 0; str[length]; length++)
	;
	return (length);
}


/**
 * regex_match - checks for pattern in str
 *
 * @str: string to find patter in
 * @pattern: pattern string
 *
 * Return: 1 if found || 0 if not
 */
int regex_match(char const *str, char const *pattern)
{
	int stringlen = len(str), patlen = len(pattern),
	 strdex = 0, patex = 0, inf = 0, aind;
	char constant, nextchar;

	for (; patex < patlen; patex++)
	{
		constant = pattern[patex], nextchar = pattern[patex + 1];
		if (constant == '.')
		{
			if (inf && !nextchar)
				return (1);
			inf = 0;
			if (nextchar == '*')
			{
				if (!pattern[patex + 2])
					return (1);
				inf = 1;
			} else
				strdex++;
		} else
		{
			if (constant == '*')
			{
				if (inf)
					aind = patex + 1;
			} else if (nextchar == '*')
				inf = 0, strdex = astrix(constant, strdex, str);
			else if (constant == str[strdex])
				strdex++; else
			{
				if (inf)
				{
					patex = aind;
					continue; }
				return (0); }
		}
	}
	if (strdex != stringlen)
		return (0);
	return (1);
}
