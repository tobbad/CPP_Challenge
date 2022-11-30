from library import *

def loesung():
    a= array2d(2,3)
    a.set([1,2,3,4,5,6])
    print(a)
    for i in range(a.arr.shape[0]):
        for j in range(a.arr.shape[1]):
            a.arr[i][j] *= 2
    print(a)
    b= array2d(2,3)
    b.fill(1)
    a.swap(b)
    c= array2d(2,3)
    c.move(b)
    print(c)
    
  




if __name__ == "__main__":
    loesung()
