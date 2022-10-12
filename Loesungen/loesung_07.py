from library import *


if __name__ == "__main__":
    opt, args = getOpt()
    limite=int(float(args[0]))
    print_amicables(limite)
