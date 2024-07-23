#!/usr/bin/python3
"""
This module is designed to parse log data from a standard input stream,
keeping track of the total file size and the count of HTTP status codes
encountered. It provides functionality to print these statistics to the
standard output, offering insights into the nature of the traffic or log
data being analyzed.

Features:
- Tracks total file size of log entries.
- Counts occurrences of specific HTTP status codes.
- Prints accumulated statistics to standard output.

Usage:
This script is intended to be used in a pipeline where it receives log data
from a standard input stream. It can be used in conjunction with a log generator
script or a file containing log data. The script continuously reads from standard
input until interrupted, at which point it prints the final statistics
to standard output.

Example:
`./log_generator.py | ./0-stats.py`
Where `log_generator.py` is a script that outputs log data to standard output.

Dependencies:
- sys: For reading from standard input and handling interruptions.
- signal: For setting up signal handling to gracefully exit print statistics
upon receiving an interrupt signal.
"""

import sys
import signal



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
