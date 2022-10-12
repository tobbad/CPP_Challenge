from library import *


if __name__ == "__main__":
    opt, args = getOpt()
    limite=int(args[0])
    for i in range(10, limite+1):    
        res = sum_proper_divisors(i)
        #print("i %d, Res %d" %(i, res)) 
        if (res - i > 0):
            print("%d ; %d" % (i, res-i))


        
