from library import *

def loesung():
    ip1=ipv4()
    ip1.readIp()
    
    ip2=ipv4()
    ip2.readIp()
    print(" Range %d to %d" %(ip1, ip2))
    for i in ip4iter(ip1, ip2):
        print("%s" % i)
    



if __name__ == "__main__":
    loesung()
