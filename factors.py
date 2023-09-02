#!/usr/bin/python3

import sys

args = sys.argv
if len(args[1:]) != 1:
    sys.stderr.write("Usage: {} <file>".format(args[0]))

pfile = open(args[1])
lines = pfile.readlines()

factors = []
for line in lines:
    print(line, end="=")
    try:
        num = int(line)
        for div in range(2, int(num ** 0.5) + 1):
            while num % div == 0:
                factors.append(div)
                num /= div
        if num > 1:
            factors.append(int(num))
        for f in factors[:-1]:
            print("{:d}*".format(f), end="")
        print("{:d}".format(factors[-1]))
        factors = []
    except ValueError:
        print("Not a number")
