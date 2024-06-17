#!/usr/bin/python3

def minOperations(n):
    """
    Calculates the minimum number of operations required to reach given number

    Args:
        n (int): The target number.

    Returns:
        int: The minimum number of operations required.

    """
    if n < 1:
        return 0
    operation = 0
    division = 2
    while n > 1:
        while n % division == 0:
            operation += division
            n //= division
        division += 1
    return operation