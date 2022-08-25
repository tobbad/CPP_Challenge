
def loesung():
    print("Yes I am done")
    limit=input("Upper limit? ")
    limit=int(limit)
    summe=0
    for i in range(limit+1):
        if (i%3==0) or (i%5==0):
            summe += i
    print("Result is %d" % summe)

if __name__ == "__main__":
    loesung()