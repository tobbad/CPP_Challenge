from library import *

def loesung(number):
    print(longest_collatz(number))

if __name__ == "__main__":
    opt, arg = getOpt()
    loesung(int(arg[0]))
