#include "sandpiles.h"

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

void tumbler(int grid[3][3], int row, int index)
{
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

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int n = 0, index = 0, row = 0;

    add(grid1, grid2);
    printgrid(grid1);
        
    for (row = 0; row < 3; row++)
        for (index = 0; index < 3; index++)
        {
            n = grid1[row][index];
            if (n > 3)
            {
                tumbler(grid1, row, index);
                printf("current [%d][%d]\n", row, index);
                printgrid(grid1);

                grid1[row][index] -= 4;
            }
        }
    printf("TEST\n");
    printgrid(grid1);

}