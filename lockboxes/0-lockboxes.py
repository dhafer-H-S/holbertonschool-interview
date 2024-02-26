#!/usr/bin/python3
"""check if the boxes are open or not and
if not sherache for the keys if existed and open them"""


def canUnlockAll(boxes):
    n = len(boxes)
    opened = [False]*n
    opened[0] = True

    for _ in range(n):
        change = False
        for i in range(n):
            if opened[i]:
                for key in boxes[i]:
                    if key < n and not opened[key]:
                        opened[key] = True
                        change = True
        if not change:
            break

    return all(opened)
