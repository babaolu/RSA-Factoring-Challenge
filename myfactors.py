#!/usr/bin/python3

import sys

args = sys.argv
if len(args[1:]) != 1:
    sys.stderr.write("Usage: {} <file>".format(args[0]))

pfile = open(args[1])
lines = pfile.readlines()

for line in lines:
    try:
        num = int(line)
        print(num, end="=")
        for div in range(2, int(num ** 0.5) + 1):
            if num > 10 ** 18:
                from decimal import Decimal, getcontext
                getcontext().prec = 50
                num = Decimal(line)
            if num % div == 0:
                print("{:d}".format(int(num/div)), end="*")
                print("{:d}".format(div))
                break
    except ValueError:
        print("Not a number")
