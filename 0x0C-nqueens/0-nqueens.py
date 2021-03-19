#!/usr/bin/python3
import sys


def is_attack(lis, pt):
    """is_attack checks if pt is in attacking range of a queen"""
    x2, y2 = pt

    for i in lis:
        if i is None or len(i) > 2:
            return 0
        x1, y1 = i
        # diag
        if (abs(x1 - x2) == abs(y1 - y2)):
            return 0

        # horizontal
        if x1 == x2:
            return 0

        # vertical
        if y1 == y2:
            return 0
    return 1


def nqueens(N):
    """nqueens solves the N queens puzzle"""
    if len(N) != 2:
        print("Usage: nqueens N")
        return 1

    try:
        n = int(N[1])
    except ValueError:
        print("N must be a number")
        return 1

    if n < 4:
        print("N must be at least 4")
        return 1

    solutions = []
    # start of the recursion for various starting points
    for i in range(n):
        matrix = [[0 for i in range(n)] for x in range(n)]
        matrix[0][i] = 1
        fin = recurQueens(matrix, [[0, i]], 1, n, 0)
        if fin:
            solutions.append(fin)
        matrix[0][i] = 0

    keep = []
    for i in solutions:
        if sorted(i) not in keep:
            keep.append(sorted(i))

    for i in keep:
        if len(i) == n:
            print(i)


def recurQueens(matrix, solution, level, n, x):
    """The recursize part of the solution"""
    line = []
    if len(solution) == n:
        return solution

    while x < n:
        if is_attack(solution, [level, x]) == 1:
            # found a potential addition to the solution
            if [level, x] not in solution:
                # if its not marked in matrix or part of the solution mark it
                # on the matrix
                # recur with solution with addition. add after
                matrix[level][x] = 1
                solution.append([level, x])
                solve = recurQueens(matrix, solution, level + 1, n, 0)
                if len(solve) == n:
                    return solve
                else:
                    matrix[level][x] = 0
                    solution.remove(solution[-1])
                    line = recurQueens(matrix, solution, level, n, x + 1)
        x += 1
    return solution


nqueens(sys.argv)
