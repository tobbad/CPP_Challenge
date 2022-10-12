#!/urs/bin/python
from library import *

def loesung(limit):
    summe = 0
    for i in range(limit+1):
        if (i%3==0) or (i%5==0):
            summe += i
    print("%d" % summe)


if __name__ == "__main__":
    opt, arg = getOpt()
    loesung(int(arg[0]))
