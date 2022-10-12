#!/usr/bin/python
from library import *


if __name__ == "__main__":
    opt, args = getOpt()
    res = gcd(int(args[0]), int(args[1]))
    print("%d" % res)
