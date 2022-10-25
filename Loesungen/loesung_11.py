from library import *

def loesung(number):
    print(to_roman(number))

if __name__ == "__main__":
    opt, arg = getOpt()
    loesung(int(arg[0]))
