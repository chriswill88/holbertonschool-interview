#!/usr/bin/python3
"""this module contains the function to task 0"""


def pascals_rows(n):
    """this creates the rows for pascals triangle"""
    start = [1]

    if len(n) == 0:
        return [1]

    for i in range(len(n)):
        if i + 1 in range(len(n)):
            value = sum(n[i: i + 2])
        else:
            value = n[i]
        start.append(value)

    return start


def pascal_triangle(n):
    """gives the rows in the pascal_triangle"""
    triangle = []
    row = []

    for i in range(n):
        row = pascals_rows(row)
        triangle.append(row)
    return triangle
