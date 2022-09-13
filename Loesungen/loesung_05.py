from library import *


if __name__ == "__main__":
    print("Sexy Primzahlen")
    limite=input("Obere Grenze? ")
    limite=int(limite)

    for i in range(limite):
        #print(i,isPrim(i),isPrim(i+6))
        if isPrim(i) and isPrim(i+6):
            print("Result is %d & %d" % (i, i+6)) 
