#!/usr/bin/python3
import sys
import signal
"""
This module demonstrates the use of the `sys` and `signal`
standard library modules in Python.

- `sys`: This module provides access to some variables used or
maintained by the Python interpreter and to functions that interact strongly
with the interpreter. It is used to manipulate Python runtime environment.

- `signal`: This module provides mechanisms to use signal handlers in Python.
Signal handlers are used to take action in response to signals received by the
program from the operating system. This is useful for handling program
interruptions or cleanup actions.
"""


total_file_size = 0
status_code_counts = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0}
line_count = 0


def print_stats():
    """
    Print the total file size and the count of each status code.

    This function prints the total file size and the count of each status code
    in the `status_code_counts` dictionary. The total file size is obtained
    from the `total_file_size` variable.

    Example output:
    total file size: 1024
    200: 10
    404: 5
    500: 2
    """
    print(f"total file size: {total_file_size}")
    for code in sorted(status_code_counts.keys()):
        if status_code_counts[code] > 0:
            print(f"{code}: {status_code_counts[code]}")


def signal_handler(sig, frame):
    """
    Signal handler function that prints the statistics and exits the program.

    This function is called when a SIGINT signal is received. It prints the
    statistics using the `print_stats()` function and exits the program with
    a status code of 0.
    """
    print_stats()
    sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)

for line in sys.stdin:
    try:
        parts = line.split()
        if len(parts) < 9:
            continue

        status_code = int(status_code)
        file_size = int(file_size)

        if status_code not in status_code_counts:
            continue

        total_file_size += file_size
        status_code_counts[status_code] += 1

        line_count += 1
        if line_count % 10 == 0:
            print_stats()

    except Exception:
        continue

print_stats()
