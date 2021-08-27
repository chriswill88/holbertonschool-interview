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
    if num == 1 or num == 0:
      array.remove(num)
      return

    for i in array:
        if i % num == 0:
            array.remove(i)


def game(array, winner):
    """
      this function recursivly plays the prime game
    """

    for i in array:
        if is_prime(i):
            find_multiples(array, i)
            winner = 'Maria' if winner == 'Ben' else 'Ben'
        else:
            find_multiples(array, i)
    return winner


def isWinner(x, nums):
    """
      This function is the main function of the prime game,
      it returns who one.
    """
    winner = []
    if x < 1:
      return None

    for i in nums:
        winner.append(game(list(range(1, i + 1)), 'Ben'))
    if winner.count('Ben') == winner.count('Maria'):
        return None
    return 'Ben' if winner.count('Ben') > winner.count('Maria') else 'Maria'
