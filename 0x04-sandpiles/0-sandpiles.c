#include "sandpiles.h"


/**
 * ischeck - checks if the array is stable
 *
 * @grid: this is the 2d array
 * Return: 1 if not stable, 0 if it is stable
 */
int ischeck(int grid[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int index = 0; index < 3; index++)
			if (grid[i][index] > 3)
				return (1);
	return (0);
}

/**
 * fix - uses a matching grid to decide when to tumble
 *
 * @grid1: a 2d array
 * @grid2: a matching 2d array
 *
 * Return: Void
 */
void fix(int grid1[3][3], int grid2[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int index = 0; index < 3; index++)
			if (grid2[i][index] > 3)
			{
				grid1[i][index] -= 4;
				/* top */
				if (i - 1 >= 0)
					grid1[i - 1][index] += 1;
				/* bottom */
				if (i + 1 < 3)
					grid1[i + 1][index] += 1;
				/* left */
				if (index - 1 >= 0)
					grid1[i][index - 1] += 1;
				/* right */
				if (index + 1 < 3)
					grid1[i][index + 1] += 1;
			}
}

/**
 * printgrid - is a printer for the sandpiles
 *
 * @grid: a 2d array
 *
 * Return: Void
 */
void printgrid(int grid[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int index = 0; index < 3; index++)
			printf("%d ", grid[i][index]);
		printf("\n");
	}
}

/**
 * copygrid - copies one grid onto another
 *
 * @grid1: a 2d array
 * @grid2: a matching 2d array
 *
 * Return: Void
 */
void copygrid(int grid1[3][3], int grid2[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int index = 0; index < 3; index++)
			grid2[i][index] = grid1[i][index];
}

/**
 * sandpiles_sum - allows one to get the sum of two sandpiles
 *
 * @grid1: a 2d array
 * @grid2: a 2d array
 *
 * Return: Void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int index = 0; index < 3; index++)
			grid1[i][index] += grid2[i][index];

	copygrid(grid1, grid2);
	if (ischeck(grid1))
	{
		printf("=\n");
		printgrid(grid1);
	}

	fix(grid1, grid2);

	while (ischeck(grid1))
	{
		printf("=\n");
		printgrid(grid1);
		fix(grid1, grid2);
		copygrid(grid1, grid2);
	}
}
