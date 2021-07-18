#!/usr/bin/python3
"""This module contains an interview solution"""


def island_perimeter(grid):
    """this function gets the perimeter of the island made of arrays"""
    sumate = 0
    rows = len(grid)
    eles = len(grid[0])

    for row in range(rows):
        for ele in range(eles):
            if grid[row][ele] == 1 and 0 < row < rows - 1 and 0 < ele < eles - 1:
                sumate += 1 if grid[row + 1][ele] == 0 else 0
                sumate += 1 if grid[row - 1][ele] == 0 else 0
                sumate += 1 if grid[row][ele + 1] == 0 else 0
                sumate += 1 if grid[row][ele - 1] == 0 else 0

    return sumate
