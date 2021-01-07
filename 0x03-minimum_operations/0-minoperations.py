#!/usr/bin/python3
"""this modual contains the function min0pperations"""


def minOperations(n):
    """
    finds the minimum operations to get from 1 to n
    useing only copy and paste methods.
    """
    t, copy, paper = 1, 1, 1

    if (n < 2):
        return 0

    while paper < n and paper != n:
        if n % paper == 0 and paper != 1 and paper + copy < n:
            copy = paper
            t += 1
            paper += copy
        else:
            paper += copy
        t += 1
    return t
