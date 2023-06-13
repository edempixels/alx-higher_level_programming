#!/usr/bin/env python3

def no_c(my_string):
    copy = [char for char in my_string if char.lower() != 'c']
    return ''.join(copy)
