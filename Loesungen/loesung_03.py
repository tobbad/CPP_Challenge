
from solution_lib import *


if __name__ == "__main__":
    number_1=input("Zahl 1? ")
    number_1=int(number_1)
    number_2=input("Zahl 2? ")
    number_2=int(number_2)

    res = gcd(number_1, number_2)
    print("Result is %d" % res) 
