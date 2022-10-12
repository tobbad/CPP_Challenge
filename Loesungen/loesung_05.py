from library import *


if __name__ == "__main__":
    opt, args = getOpt()
    limite = int(args[0])
    for i in range(limite):
        #print(i,isPrim(i),isPrim(i+6))
        if isPrim(i) and isPrim(i+6):
            print("%d ; %d" % (i, i+6))
