#!/usr/bin/python3
"""check if the boxes are open or not and
if not sherache for the keys if existed and open them"""


def canUnlockAll(boxes):
    len(boxes)
    unlocked = [False] * len(boxes)
    unlocked[0] = True
    queue = [0]
    while queue:
        box = queue.pop(0)
        for key in boxes[box]:
            if key < len(boxes) and not unlocked[key]:
                unlocked[key] = True
                queue.append(key)
    return all(unlocked)
