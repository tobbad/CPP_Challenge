from library import *

def loesung():
    ip1=ipv4()
    ip1.readIp()
    
    ip2=ipv4()
    ip2.readIp()
    for i in range(int(ip1), int(ip2)):
        print("%s" % i)
    



if __name__ == "__main__":
    loesung()
