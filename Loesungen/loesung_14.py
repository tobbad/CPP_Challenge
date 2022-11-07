from library import *

def loesung(isbn):
    
    print(validate_isbn_10(isbn))

if __name__ == "__main__":
    opt, arg = getOpt()
    assert(validate_isbn_10("0306406152"))
    assert(not validate_isbn_10("0306406151"))

    loesung(arg[0])
