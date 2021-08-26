#!/usr/bin/python3
"""This modual contains the function used in Task 0"""


def is_prime(n):
    """
      this function checks if the number is a prime
    """
    if n <= 1:
        return 0

    for i in range(2, int(n / 2)):
        if not (n % i):
            return 0
    return 1


def find_multiples(array, num):
    """
      this function removes the number and any
      of the multiples from the array
    """
    for i in array:
        if i % num == 0:
            array.remove(i)


def game(array, winner):
    """
      this function recursivly plays the prime game
    """
    if not len(array):
        return winner

    for i in array:
        if is_prime(i):
            find_multiples(array, i)
            winner = 'Mary' if winner == 'Ben' else 'Ben'
            winner = game(array, winner)
    return winner


def isWinner(x, nums):
    """
      This function is the main function of the prime game,
      it returns who one.
    """
    winner = []

    for i in nums:
        winner.append(game(list(range(1, i + 1)), 'Ben'))
    if winner.count('Ben') == winner.count('Mary'):
        return None
    return 'Ben' if winner.count('Ben') > winner.count('Mary') else 'Mary'
