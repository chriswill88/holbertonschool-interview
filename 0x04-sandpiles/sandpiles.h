#ifndef __LOL__
#define __LOL__

#include <stdio.h>

int ischeck(int grid[3][3]);
void fix(int grid1[3][3], int grid2[3][3]);
void printgrid(int grid[3][3]);
void tumbler(int grid[3][3], int row, int index);
void copygrid(int grid1[3][3], int grid2[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif
