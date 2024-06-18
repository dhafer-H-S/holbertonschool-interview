#!/usr/bin/python3

"""math module """
import math

def minOperations(n):
    if n < 2:
        return 0
    
    operations = 0
    factor = 2
    
    """Check for smallest factors first"""
    while factor * factor <= n:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1
    
    """If n is still greater than 1, then it's prime"""
    if n > 1:
        operations += n
    
    return operations