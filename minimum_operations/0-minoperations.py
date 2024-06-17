#!/usr/bin/env python3
def minOperations(n):
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