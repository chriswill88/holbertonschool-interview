#!/usr/bin/python3
"""This module contains the function for task 0"""


def next_max(maxi, walls):
    """helper function for this algorithm"""
    if len(walls) == 0:
        return 0, 1
    index = 0
    relative_max = max(walls)
    maxpos = walls.index(relative_max)
    container = []
    hold = 0

    if relative_max > maxi:
        while index < len(walls):
            if walls[index] > maxi:
                container = walls[:index]
                maxpos = index
                if maxi < relative_max:
                    relative_max = maxi
                break
            hold += 1
            index += 1
    else:
        container = walls[:maxpos]
        hold = maxpos
    if hold == 0:
        return 0, maxpos + 1

    retainer = hold * relative_max - sum(container)
    return retainer, maxpos + 1


def rain(walls):
    """
    Task 0 - rain
    takes the sum of the rain withen walls as represented by python lists
    """
    retained = 0
    i = 0

    if not walls or len(walls) == 0:
        return 0
    length = len(walls)
    if length <= 2:
        return 0

    while i < length:
        hold = 0
        if walls[i] > 0:
            hold, indAdd = next_max(walls[i], walls[i + 1:])
            i += indAdd
        else:
            i += 1
        retained += hold

    return retained
