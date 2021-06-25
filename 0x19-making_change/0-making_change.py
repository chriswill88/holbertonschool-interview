#!/usr/bin/python3
"""This module contains the function for 0x19"""


def makeChange(coins, total):
    if total <= 0:
        return -1
    
    coin = 0
    rev = sorted(coins, reverse=True)
    
    for i in rev:
        mul = total // i
        coin += mul
        total -= mul * i
    if total > 0:
        return -1
    return coin