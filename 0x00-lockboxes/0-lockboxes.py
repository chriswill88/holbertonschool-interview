#!/usr/bin/python3
import sys
"""
This modual contains the lockbox function for task 0 of 0x00. Lockboxes.
"""
sys.setrecursionlimit(1500)


def unlocky(timeOp, boxes, box, keyHolder):
    """unlocky function for task 0"""
    if timeOp > len(boxes):
        return(False)

    for key in box:
        if (key not in keyHolder):
            if (key < len(boxes)):
                keyHolder.append(key)
                unlocky(timeOp + 1, boxes, boxes[key], keyHolder)

    if (len(keyHolder) == len(boxes)):
        return(True)

    return(False)


def canUnlockAll(boxes):
    """canUnlockall function for task 0"""
    keyHolder = [0]
    if (len(boxes) == 1):
        return True

    if (not boxes[0]):
        return False
    box = boxes[0]
    key = box[0]
    timeOp = 1
    return (unlocky(timeOp, boxes, box, keyHolder))
