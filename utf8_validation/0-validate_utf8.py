#!/usr/bin/python3


def validUTF8(data):
    def is_valid_byte(byte, mask, expected):
        """ Helper function to validate a byte against mask and expected pattern """
        return (byte & mask) == expected

    i = 0
    while i < len(data):
        byte = data[i]
        if byte > 255:
            # Integer out of byte range
            return False
        elif byte & 0b10000000 == 0:
            # 1-byte character (0xxxxxxx)
            i += 1
        elif is_valid_byte(byte, 0b11100000, 0b11000000):
            # 2-byte character (110xxxxx 10xxxxxx)
            if i + 1 >= len(data) or not is_valid_byte(data[i + 1], 0b11000000, 0b10000000):
                return False
            i += 2
        elif is_valid_byte(byte, 0b11110000, 0b11100000):
            # 3-byte character (1110xxxx 10xxxxxx 10xxxxxx)
            if (i + 2 >= len(data) or
                not is_valid_byte(data[i + 1], 0b11000000, 0b10000000) or
                not is_valid_byte(data[i + 2], 0b11000000, 0b10000000)):
                return False
            i += 3
        elif is_valid_byte(byte, 0b11111000, 0b11110000):
            # 4-byte character (11110xxx 10xxxxxx 10xxxxxx 10xxxxxx)
            if (i + 3 >= len(data) or
                not is_valid_byte(data[i + 1], 0b11000000, 0b10000000) or
                not is_valid_byte(data[i + 2], 0b11000000, 0b10000000) or
                not is_valid_byte(data[i + 3], 0b11000000, 0b10000000)):
                return False
            i += 4
        else:
            return False
    return True
