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

def isPrim(limite):
    if (limite<=3):
        return limite >1
    elif (limite%2==0) or (limite%3==0):
        return False
    else:
        for i in range(5,limite+1,2):
            if (limite%i) or limite%(i+2):
                return False
    return True
    