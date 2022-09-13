from library import *


if __name__ == "__main__":
    print("Abundnte Zahlen")
    limite=input("Obere Grenze? ")
    limite=int(limite)
    for i in range(10, limite+1):    
        res=sum_proper_divisors(i)
        #print("i %d, Res %d" %(i, res)) 
        if (res-i>0):
            print("%d; Abundance = %d" % (i, res-i))


        