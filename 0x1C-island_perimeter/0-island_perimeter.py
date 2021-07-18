#!/usr/bin/python3
"""This module contains an interview solution"""


def island_perimeter(grid):
    """this function gets the perimeter of the island made of arrays"""
    sumate = 0
    rows = len(grid)
    eles = len(grid[0])

    for row in range(rows):
        for ele in range(eles):
            if grid[row][ele] == 1:
                sumate += 4
                # down
                sumate -= 1 if row + 1 < rows and grid[
                    row + 1][ele] == 1 else 0
                # up
                sumate -= 1 if row - 1 >= 0 and grid[
                    row - 1][ele] == 1 else 0
                # right
                sumate -= 1 if ele + 1 < eles and grid[
                    row][ele + 1] == 1 else 0
                # left
                sumate -= 1 if ele - 1 >= 0 and grid[
                    row][ele - 1] == 1 else 0
    return sumate
