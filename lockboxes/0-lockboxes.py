#!/usr/bin/python3
"""check if the boxes are open or not and
if not sherache for the keys if existed and open them"""


def canUnlockAll(boxes):
    unlocked = [0]
    for box_id, box in enumerate(boxes):
        if not box:
            continue
        for key in box:
            if key < len(boxes) and key not in unlocked and key != box_id:
                unlocked.append(key)
    if len(unlocked) == len(boxes):
        return True
    return False
