#include "sandpiles.h"

void tumbler(int grid[3][3], int row, int index)
{
    grid[row][index] -= 4;
    // top
    if (row-1 >= 0)
        grid[row-1][index] += 1;
    // bottom
    if (row+1 < 3)
        grid[row+1][index] += 1;
    // left
    if (index-1 >= 0)
        grid[row][index-1] += 1;
    // right
    if (index+1 < 3)
        grid[row][index+1] += 1;
}

int ischeck(int grid[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int index = 0; index < 3; index++)
            if (grid[i][index] > 3)
            {
                tumbler(grid, i, index);
                return (1);
            }
    return (0);
}

void printgrid(int grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int index = 0; index < 3; index++)
            printf("%d ", grid[i][index]);
        printf("\n");
    }
}

void add(int grid1[3][3], int grid2[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int index = 0; index < 3; index++)
            grid1[i][index] += grid2[i][index];
}



void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

    add(grid1, grid2);
    printgrid(grid1);
        
    while (ischeck(grid1))
    {
        printf("in loop\n");
        printgrid(grid1);
    }


    printf("TEST\n");
    printgrid(grid1);

}