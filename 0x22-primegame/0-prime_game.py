#!/usr/bin/python3
"""This modual contains the function used in Task 0"""


def is_prime(n):
    """
      this function checks if the number is a prime
    """
    for i in range(int(n**(1 / 2)), int(n / 2)):
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
            if (num == i and is_prime(i)):
                continue
            array.remove(i)


def game(array, winner):
    """
      this function recursivly plays the prime game
    """
    for _ in array:
        winner = 'Maria' if winner == 'Ben' else 'Ben'
    return winner


def list_maker(array):
    """
      this function recursivly plays the prime game
    """
    i = 0
    while i < len(array):
        value = array[i]
        find_multiples(array, value)
        i += 1

    return array


def get_relevant_primes(primes, num):
    return [i for i in primes if i <= num]


def isWinner(x, nums):
    """
      This function is the main function of the prime game,
      it returns who one.
    """
    winner = []
    if x < 1:
        return None
    primes = list_maker(list(range(2, max(nums) + 1)))

    for i in nums:
        winner.append(game(get_relevant_primes(primes, i), 'Ben'))
    if winner.count('Ben') == winner.count('Maria'):
        return None
    return 'Ben' if winner.count('Ben') > winner.count('Maria') else 'Maria'
