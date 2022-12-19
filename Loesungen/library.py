
import numpy as np
from math import *
import random
import optparse
import struct
import os


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
        
def longest_collatz(limite):
    cache = [0]*(limite+1)
    length = 0
    for i in range(2, limite+1):
        n = i
        steps = 0
        while ((n!=1) and (n>=i)):
            if (n%2 == 0):
                n = int(n/2)
            else:
                n = int(3*n+1)
            steps+=1
        cache[i] = steps + cache[n]
        if cache[i]>length:
            length =  cache[i]
            number = i
   
    return number, length
    
def compute_pi(samples = 1000000):
    hit = 0
    for i in range(samples):
        x = random.random()
        y = random.random()
        if y<sqrt(1-x**2):
            hit += 1
    return 4.0*hit/samples

def validate_isbn_10(isbn):
    #print(type(isbn), isbn)
    if not type(isbn)==str:
        print("Wrong datatype")
        return False
    if len(isbn) != 10:
        print("Wrong size")
        return False
    if not isbn.isdigit():
        print("Is not number")
        return False
    sum = 0
    for (w,d) in zip(range(10,0,-1), isbn):
        sum += w*(ord(d)-ord('0'))
        #print(w,ord(d)-ord('0'), sum%11)
    return (sum%11==0)

class ip4iter:
    def __init__(self, minimum, maximum):
        print(type(minimum), type(maximum))
        self._idx = int(minimum)
        self._end = int(maximum)
        print("Set miniumum to %d" % self._idx)
        print("Set maximum¨ to %d" % self._end)

    def __iter__(self):
        return self

    def __next__(self):
        self._idx += 1
        if self._idx < self._end:
            return ipv4(self._idx)
        raise StopIteration

class ipv4:
    def __init__(self, ip = None):
        self._ip = [0,0,0,0]
        self._ipu32 = 0
        if ip is None:
            return None 
        if type(ip) == type([] or type(ip) == type(())) and length(ip)==4:
            print("Is tuple ", ip)
            for i in range(4):
                self._ip[i]= ip[i] 
        elif type(ip) == int:
            self._ipu32 = ip
            self._ip = [(ip>>24)&0xFF, (ip>>16)&0xFF, (ip>>8)&0xFF, ip&0xFF]
        self._ipu32 = int.from_bytes(struct.pack("BBBB", *self._ip), byteorder='big', signed=False)

    def __eq__(self, other_ip):
        if type(other_ip) == type(self):
            self._ip= ipv4(other_ip)

    def __iter__(self):
        return self.__

    def __str__(self):
        res = "[%d.%d.%d.%d] (%d)" %(self._ip[0], self._ip[1], self._ip[2], self._ip[3], self._ipu32 )
        return res

    def readIp(self):
        ip = input("IP in dot notation ")
        ip_split = ip.split(".")
        if len(ip_split) != 4:
            print("Dot notation contains 4 values")
        self._ip = [int(i) for i in ip_split]
        self._ipu32 = (self._ip[0]<<24) + (self._ip[1]<<16) + (self._ip[2]<<8) + self._ip[3]
        print(self)

    def __add__(self, nr):
        self._ipu32 + nr

    def __int__(self):
        return self._ipu32
    
class array2d:
    def __init__(self, xSize, ySize, dtype=np.int32):
        self._arr= np.zeros((xSize, ySize),dtype=dtype)
        
    def set(self, other):
        if type(other) == type(self):
            for i in range(self._arr.shape[0]):
                for j in range(self._arr.shape[1]):
                    self._arr[i][j] = other.arr[i][j]
        if type(other) != type([]):
            raise ValueError("Wrong datatype given, must be list")
        if len(other) != self._arr.shape[0]*self._arr.shape[1]:
            errStr="Wrong vector size, given, must be %d" % (self._arr.shape[0]*self._arr.shape[1])
            raise ValueError(errStr)
        idx =0
        for i in range(self._arr.shape[0]):
            for j in range(self._arr.shape[1]):
                self._arr[i][j] = other[idx]
                idx+=1
    
    def __str__(self):
        res="[\n"
        for i in range(self._arr.shape[0]):
            for j in range(self._arr.shape[1]):
                if j==0:
                    res += " ["
                res += "%d " %self._arr[i][j]
            res += "]\n"
        res += "]\n"
        return res
    
    @property
    def size(self):
        return self._arr.shape
    
    @property
    def arr(self):
        return self._arr
    
    def fill(self,value):
        for i in range(self._arr.shape[0]):
            for j in range(self._arr.shape[1]):
                self._arr[i][j] = value
                
    def swap(self, other):    
        if type(other) != type(self):
            raise ValueError("Wrong datatype, other must be %s" % (type(self)))
        for i in range(self._arr.shape[0]):
            for j in range(self._arr.shape[1]):
                a = self._arr[i][j]
                b = other.arr[i][j]
                other.arr[i][j] = a
                self._arr[i][j] = b 
            
    def move(self, other):
        if type(other) != type(self):
            raise ValueError("Wrong datatype, other must be %s" % (type(self)))
        for i in range(self._arr.shape[0]):
            for j in range(self._arr.shape[1]):
                self._arr[i][j] = other.arr[i][j]

def factorial(n):
    res = 1
    for i in range(2,n+1):
        res *= i
    return res
    


def binomial_koeffizent(n, k):
    #print("%d tief %d " %(n,k), end= "")
    if k>n:
        res = 0
    else:
        zaehler = factorial(n)
        nenner =factorial(k)*factorial(n-k)
        res = zaehler/nenner
    #print(res)
    return res
    
    

def num_of_digits(nr):
    if nr>0:
        return int(log10(nr)+1)
    else:
        return 1
   
def pascal_dreieck(line_cnt, scan=True):
    n = num_of_digits(binomial_koeffizent(line_cnt,line_cnt>>1))
    lines=[((line_cnt<<1)*" ")+"1"]
    fmt = "{:<%d} "%n
    for i in range(1, line_cnt):
        line = ' '*((line_cnt<<1)-(2*i))
        for n in range(0, i+1):
            res = int(binomial_koeffizent(i, n))
            line += fmt.format(res )
        line+= "\n"
        lines.append(line)
    return lines        
        
def recursive_size(root_folder, res=None):
    if res ==None:
        res = {root_folder:0}
    
    for root, subdirs, files in os.walk(root_folder, True): 
        if root not in res:
            res[root]=0
        file_size = 0
        for f in files:
            fname = os.path.join(root, f)
            file_stat = os.stat(fname)
            file_size += file_stat.st_size
        res[root]= file_size
        print("Folder %s size is %d" % (root, file_size))
        for d in subdirs:
            subFolderName = os.path.join(root, d)
            print("SubDir %s"% (subFolderName))
            res = recursive_size(subFolderName, res)
        return res
    