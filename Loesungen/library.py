from math import *

def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b, a % b)


def lcm(a,b):
    h = gcd(a,b)
    if h:
        return (a*(b/h))
    else:
        return 0

def isPrim(lim):
    if (lim<3):
        return lim >1
    else:
        checkLim=int(ceil(sqrt((lim))))
        #print("Check up to %d" % (checkLim))
        for i in range(2,checkLim+1):
            #print("Check %d" %i)
            if lim%i==0:
                return False
    return True

def sum_proper_divisors(num):
    res = 1
    for i in range(2,int(ceil(sqrt(num)))):
        #print("Check %d" %i)
        if num%i==0:
            res+=i if (i==num/i) else (i+num/i)
    #print("num: %d Sum %d" %(num, res))
    return res
    
def print_amicables(limit):
	for  number in range(4, limit):
		sum1 = sum_proper_divisors(number);
		if (sum1 < limit):
			sum2 = sum_proper_divisors(sum1);
			if ((sum2==number) and (number!=sum1)):
				print("%d, %d" % (number, sum1))

def print_armstong():
    for i in range(1,10):
        for j in range(1,10):
            for k in range(1,10):
                abc=100*i+10*j+k
                abm=i*i*i+j*j*j+k*k*k
                if  abc==abm:
                    print("%d contains the square of %d, %d and %d" %(abm, i, j, k))