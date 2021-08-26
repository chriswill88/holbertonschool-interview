#!/usr/bin/python3


def is_prime(n):
    if n <= 1:
        return 0

    l = range(2, int(n / 2))

    for i in range(2, int(n / 2)):
        if not (n % i):
            return 0
    return 1


def find_multiples(array, num):
    for i in array:
        if i % num == 0:
            array.remove(i)


def game(array, winner):
    if not len(array):
        return winner

    for i in array:
        if is_prime(i):
            find_multiples(array, i)
            winner = 'Mary' if winner == 'Ben' else 'Ben'
            winner = game(array, winner)
    return winner


def isWinner(x, nums):
    winner = []

    for i in nums:
        winner.append(game(list(range(1, i + 1)), 'Ben'))
    if winner.count('Ben') == winner.count('Mary'):
        return None
    return 'Ben' if winner.count('Ben') > winner.count('Mary') else 'Mary'
