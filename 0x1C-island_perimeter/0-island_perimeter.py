#!/usr/bin/python3
"""This module contains an interview solution"""


def bounderyCheck(grid):
    sumL = 0
    sumR = 0

    if sum(grid[0]) != 0:
        return False
    if sum(grid[len(grid) - 1]) != 0:
        return False

    for i in range(len(grid)):
        sumL += grid[i][0]
        sumR += grid[i][len(grid)]
    return True if sumL + sumR == 0 else False
    

def island_perimeter(grid):
    """this function gets the perimeter of the island made of arrays"""
    sumate = 0
    if bounderyCheck(grid) == False:
        return 0

    for row in range(len(grid)):
        for ele in range(len(grid[row])):
            if grid[row][ele] == 1:
                try:
                    sumate += 1 if grid[row][ele - 1] == 0 else 0
                    sumate += 1 if grid[row - 1][ele] == 0 else 0
                    sumate += 1 if grid[row + 1][ele] == 0 else 0
                    sumate += 1 if grid[row][ele + 1] == 0 else 0
                except Exception:
                    pass
    return sumate
