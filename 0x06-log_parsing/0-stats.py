#!/usr/bin/python3
"""this script parses log files"""
from signal import signal, SIGINT
import sys
import re
import select


i = 0
size = 0
statCode = {
    200: 0, 301: 0,
    400: 0, 401: 0,
    403: 0, 404: 0,
    405: 0, 500: 0
    }


def signol(sig, frame):
    """signol: handeler"""
    output(size, statCode)


def output(s, sC):
    """prints the proper output"""
    print("File size: {}".format(size))
    for stat, freq in sorted(statCode.items()):
        if freq:
            print("{}: {}".format(stat, freq))


signal(SIGINT, signol)
if select.select([sys.stdin, ], [], [], 0.0)[0]:
    for data in sys.stdin:
        if i and i % 10 == 0:
            output(size, statCode)
        try:
            code = re.split(' ', data)[-2:-1]
            size += int(re.split(' ', data)[-1])
            if int(code[0]) in statCode:
                statCode[int(code[0])] += 1
            i += 1
        except Exception:
            pass

output(size, statCode)
