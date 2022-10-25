from math import *
import optparse

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
                    print("%d ; %d ; %d ; %d" %(abm, i, j, k))
def getOpt():
    p = optparse.OptionParser()
    opt, args = p.parse_args()
    return opt, args

def prime_factors(number):
    factors=[]
    while (number%2==0):
        factors.append(2)
        number/=2
    uplim=int(ceil(sqrt(number)))+1
    for i in range(3,uplim,2):
        while (number%i==0):
            factors.append(i)
            number=number/i
    if number>2:
        factors.append(number)
    return factors
        

def gray_encode(number):
    return number^(number>>1)


def gray_decode(gray):
    for  bitPos in range(31,1,-1):
        bitMask = 1<<bitPos
        if gray&bitMask:
            gray ^= bitMask >>1
    return gray

def to_binary(number, digits=5):
    mask= (1<<digits)-1
    number &= mask
    string=""
    for i in range(digits):
        if number&(1<<i)==0:
            string = "0"+string
        else:
            string = "1"+string
    return string

def to_roman(number):
    if number>=10000:
        return "Not possible"
    else:
        table=(
            (1000, "M"),
            (900 , "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1 , "I")            
        )
        res=""
        for t in table:
            while number >= t[0]:
                number -= t[0]
                res += t[1]
        return res
        
    
