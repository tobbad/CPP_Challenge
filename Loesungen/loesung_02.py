
from library import *


if __name__ == "__main__":
    number_1=input("Zahl a? ")
    number_1=int(number_1)
    number_2=input("Zahl b? ")
    number_2=int(number_2)

    res = gcd(number_1, number_2)
    print("Result is %d" % res) 
