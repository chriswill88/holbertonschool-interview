#!/usr/bin/python3
"""This module contains the function for task 0"""


def box_open(boxes, key, open_boxes, n, solution):
    """box_open - the recursive algorithm"""
    if len(open_boxes) == len(boxes) or (
            0 not in open_boxes and len(open_boxes) + 1 == len(boxes)):
        return open_boxes
    for i in boxes[key]:
        if i not in open_boxes:
            solution = box_open(boxes, i, open_boxes + [i], n + 1, solution)
    if solution:
        return solution


def canUnlockAll(boxes):
    """
    canUnlockAll - checks if all boxes can be unlocked
    True if able to unlock all and false if not.
    """
    if not isinstance(boxes, list) or len(boxes) == 0:
        return False

    if not (all(isinstance(x, list) for x in boxes)):
        return False

    if len(boxes) == 1:
        return True
    return True if box_open(boxes, 0, [], 1, None) else False
