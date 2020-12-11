#!/usr/bin/python3
import sys
"""This module contains the function for task 0"""
sys.setrecursionlimit(1500)


def box_open(boxes, key, open_boxes, timeop):
    """box_open - the recursive algorithm"""
    if timeop > len(boxes):
        return False

    for i in boxes[key]:
        if i not in open_boxes:
            if i < len(boxes):
                open_boxes.append(i)
                box_open(boxes, i, open_boxes, timeop + 1)

    if len(open_boxes) == len(boxes):
        return True


def canUnlockAll(boxes):
    """
    canUnlockAll - checks if all boxes can be unlocked
    True if able to unlock all and false if not.
    """
    if (len(boxes) == 1):
        return True

    if (not boxes[0]):
        return False
    return True if box_open(boxes, 0, [], 1) else False
