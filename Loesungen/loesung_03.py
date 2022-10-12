#!/usr/nin/python
from library import *


if __name__ == "__main__":
    opt, args = getOpt()
    res = lcm(int(args[0]), int(args[1]))
    print("%d" % res)
