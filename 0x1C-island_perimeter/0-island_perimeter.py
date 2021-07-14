#!/usr/bin/python3
"""This module contains an interview solution"""


def island_perimeter(grid):
    """this function gets the perimeter of the island made of arrays"""
    summer = 0

    for row in range(len(grid)):
        for ele in range(len(grid[row])):
            if grid[row][ele] == 1:
                sumate = 0
                if 0 < row < len(grid) - 1 and 0 < ele < len(grid[row]) - 1:
                    sumate += 1 if grid[row][ele - 1] == 0 else 0
                    sumate += 1 if grid[row][ele + 1] == 0 else 0
                    sumate += 1 if grid[row - 1][ele] == 0 else 0
                    sumate += 1 if grid[row + 1][ele] == 0 else 0
                    summer += sumate

    return summer
