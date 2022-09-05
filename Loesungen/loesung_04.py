from library import *


if __name__ == "__main__":
    limite=input("Obere Grenze? ")
    limite=int(limite)

    for i in range(limite, 1, -1):
        print(i)
        if isPrim(i):
            print("Result is %d" % i) 
            exit()
