#!/usr/bin/python3
"""this module contains the function for task 0"""


def nextcord(sides, j, x, y, i):
    """
    nextcord -
        return the next x, y value
    """
    if sides % 2 == 0:
        y = j
    else:
        if sides == 3:
            y = i
        x = j
    return x, y


def rotate_slice(listy, mini, maxi):
    """
    rotate_slice -
        rotates the internal and outer square
    @listy: a 2d list
    @mini: the lowest x, y value of the square
    @maxi: the highest x, y value of the square
    """
    if mini >= maxi:
        return
    sides = []
    x = y = mini
    side = 0

    while side < 4:
        swap = [0 for i in range(mini, maxi)]
        for j in range(mini, maxi):
            x, y = nextcord(side, j, x, y, mini)
            swap[j - mini] = listy[x][y]
        sides.append(swap)
        side += 1
    x = y = mini
    ind = -1
    side = 0
    while side < 4:
        for j in range(mini, maxi):
            x, y = nextcord(side, j, x, y, mini)
            if side % 2 == 0:
                listy[x][y] = sides[ind][maxi - 1 - j]
            else:
                listy[x][y] = sides[ind][j - mini]
        ind += 1
        side += 1
    rotate_slice(listy, mini + 1, maxi - 1)


def rotate_2d_matrix(listy):
    """
    rotate_2d_matrix:
        This function works by rotating the
        internal squares withen a 2d array
    rotates a 2d array by 90 degrees
    """
    maxi = len(listy)
    rotate_slice(listy, 0, maxi)
