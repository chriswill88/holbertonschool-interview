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
              try:
                sumate -= 1 if grid[row + 1][ele] == 1 else -1
              except Exception:
                pass
              # up
              try:
                sumate -= 1 if grid[row - 1][ele] == 1 else -1
              except Exception:
                pass
              # right
              try:
                sumate -= 1 if grid[row][ele + 1] == 1 else -1
              except Exception:
                pass
              # left
              try:
                sumate -= 1 if grid[row][ele - 1] == 1 else -1
              except Exception:
                pass

    return sumate
