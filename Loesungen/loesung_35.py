from library import *

def loesung():
    
    res = recursive_size(".")
    print(res)
    for d in res:
        print("Folder %s , size= %d" % (d, res[d]))

if __name__ == "__main__":
    loesung()
