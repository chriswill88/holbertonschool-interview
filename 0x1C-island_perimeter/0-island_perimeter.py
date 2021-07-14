#!/usr/bin/python3
"""This module contains an interview solution"""


def island_perimeter(grid):
    """this function gets the perimeter of the island made of arrays"""
    sumate = 0
    if len(grid) < 3:
        return sumate

    for row in range(len(grid)):
        for ele in range(len(grid[row])):
            if 0 < row < len(grid) - 1 and 0 < ele < len(grid[row]) - 1: 
                if grid[row][ele] == 1:
                    sumate += 1 if grid[row][ele - 1] == 0 else 0
                    sumate += 1 if grid[row - 1][ele] == 0 else 0
                    sumate += 1 if grid[row + 1][ele] == 0 else 0
                    sumate += 1 if grid[row][ele + 1] == 0 else 0
                    print(sumate)
    return sumate
