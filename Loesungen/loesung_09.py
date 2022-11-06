from library import *


if __name__ == "__main__":
    opt, args = getOpt()
    limite=int(args[0])

    print(prime_factors(limite))