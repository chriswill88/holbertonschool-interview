#!/usr/bin/python3
"""This module contains the function for 0x19"""


def makeChange(coins, total):
    """tries to see how much change can be used to complete the total"""
    if total <= 0:
        return 0

    coin = 0
    rev = sorted(coins, reverse=True)

    for i in rev:
        mul = total // i
        coin += mul
        total -= mul * i
    if total > 0:
        return -1
    return coin
