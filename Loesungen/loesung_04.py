from library import *


if __name__ == "__main__":
    opt, args = getOpt()
    limite=int(args[0])

    for i in range(limite, 1, -1):
        if isPrim(i):
            print("%d" % i)
            exit()
