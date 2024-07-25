#!/usr/bin/python3
"""utf8"""

def validUTF8(data):
    """
    Determine if a given list of integers represents a valid UTF-8 encoding.

    UTF-8 is a variable-length character encoding for Unicode. Characters can
    be represented by 1 to 4 bytes in UTF-8 encoding. This function validates
    if the provided list of integers conforms to the UTF-8 encoding rules.

    Parameters:
    data (list of int): A list of integers where each integer represents 1 byte
                        of data (0 to 255).

    Returns:
    bool: True if the data is a valid UTF-8 encoding, otherwise False.
    """
    
    def is_continuation_byte(byte):
        """
        Check if a byte is a continuation byte in UTF-8 encoding.

        Continuation bytes in UTF-8 start with '10' in binary (0x80 to 0xBF in hexadecimal).

        Parameters:
        byte (int): A single byte represented as an integer (0 to 255).

        Returns:
        bool: True if the byte is a continuation byte, otherwise False.
        """
        return (byte & 0xC0) == 0x80

    num_bytes = 0  

    for byte in data:
        if (byte & 0x80) == 0:
            if num_bytes > 0:
                return False
            num_bytes = 0
        elif (byte & 0xE0) == 0xC0:
            if num_bytes > 0:
                return False
            num_bytes = 1
        elif (byte & 0xF0) == 0xE0:
            if num_bytes > 0:
                return False
            num_bytes = 2
        elif (byte & 0xF8) == 0xF0:
            if num_bytes > 0:
                return False
            num_bytes = 3
        else:
            return False

        if num_bytes > 0:
            if not is_continuation_byte(byte):
                return False
            num_bytes -= 1

    return num_bytes == 0
