from library import *


if __name__ == "__main__":
    limite=input("Obere Grenze? ")
    limite=int(limite)

    for i in range(limite):
        if isPrim(i):
            print("    Is Prim: %d" % i) 
