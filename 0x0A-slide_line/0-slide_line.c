#include "slide_line.h"

/**
 * slide_line - single line 2048
 * @line: the int array
 * @size: the size of the int array
 * @direction: the direction of the shift
 * Return: 1 for success and 0 for fail
 */
int slide_line(int *line, size_t size, int direction)
{
	int s = size, n_line[99];
	int i = direction == SLIDE_LEFT ? 0 : size - 1, n = i, x = 0;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	while (x < 99)
	{
		n_line[x] = 0;
		x++;
	}
	while (direction == SLIDE_LEFT ? i < s : i >= 0)
	{
		if (line[i] != 0)
		{
			if (n_line[n] && line[i] == n_line[n])
			{
				n_line[n] += line[i];
				direction == SLIDE_LEFT ? n++ : n--;
			} else if (n_line[n] && line[i] != n_line[n])
			{
				direction == SLIDE_LEFT ? n++ : n--;
				n_line[n] += line[i];
			} else if (!n_line[n])
				n_line[n] += line[i];
		}
		direction == SLIDE_LEFT ? i++ : i--;
	}
	for (i = 0; i < s; i++)
		line[i] = n_line[i];
	return (1);
}
