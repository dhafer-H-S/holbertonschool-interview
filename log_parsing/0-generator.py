#!/usr/bin/python3
import random
import sys
from time import sleep
import datetime


def generate_logs():
    """
    Generates random log entries and prints them to stdout.

    Each log entry consists of an IP address, timestamp, HTTP request response
    code, and response size.
    The IP address is a random combination of four numbers between 1 and 255.
    The timestamp is the current date and time.
    The HTTP request is a fixed string "GET /projects/260 HTTP/1.1".
    The response code is randomly chosen from a list of possible codes.
    The response size is a random number between 1 and 1024.

    The log entries are printed to stdout using the format:
    "{IP address} - [{timestamp}]
    \"GET /projects/260 HTTP/1.1\" {response code} {response size}"

    The function generates 10,000 log entries with a random delay
    between each entry.
    """
    for i in range(10000):
        sleep(random.random())
        sys.stdout.write(
            "{:d}.{:d}.{:d}.{:d} - [{}] \"GET /projects/260 HTTP/1.1\" {} {}\n" .format(
                random.randint(
                    1, 255), random.randint(
                    1, 255), random.randint(
                    1, 255), random.randint(
                        1, 255), datetime.datetime.now(), random.choice(
                            [
                                200, 301, 400, 401, 403, 404, 405, 500]), random.randint(
                    1, 1024)))
        sys.stdout.flush()
