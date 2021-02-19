#!/usr/bin/python3
"""This modual contains the function used in Task 0"""


def validUTF8(data):
    """
        A method that determines if a given data set
        represents a valid UTF-8 encoding
    """

    utf8_data = ["{0:08b}".format(i) for i in data]
    utf8_data = [i[-8:] for i in utf8_data]
    i = 0

    while i < len(utf8_data):
        try:
            if utf8_data[i][:3] == '110':
                t1 = utf8_data[i + 1]
                if t1[:2] != '10':
                    return False
                i += 1

            elif utf8_data[i][:4] == '1110':
                s1, s2 = utf8_data[i + 1: i + 3]
                if s1[:2] != '10' or s2[:2] != '10':
                    return False
                i += 2

            elif utf8_data[i][:5] == '11110':
                s1, s2, s3 = utf8_data[i + 1: i + 4]
                s1 = s1[:2]
                s2 = s2[:2]
                s3 = s3[:2]
                if ('10' == s1 == s2 == s3) is False:
                    return False
                i += 3

            elif utf8_data[i][0] != '0':
                return False

            i += 1
        except Exception:
            return False

    return True
