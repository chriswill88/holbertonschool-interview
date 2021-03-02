#include "menger.h"


/**
 * menger - this function creates a menger carpet
 * @level: the depth of the carpet
 * Return: Void
 */
void menger(int level)
{
	int size = pow(3, level), unit = 0, i, x, lev, subsize, subI, subX;
	int temp;

	for (i = 0; i < size; i++)
	{
		for (x = 0; x < size; x++)
		{
			temp = 0;
			for (lev = level; lev >= 0; lev--)
			{
				subsize = pow(3, lev);
				unit = (subsize / 3);
				if (unit < 1)
					break;
				subI = (i + 1) % (unit * 3);
				subX = (x + 1) % (unit * 3);
				if ((subI > unit && subI <= unit * 2) && (subX > unit && subX <= unit * 2))
					temp = 1;
			}
			if (temp)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}

