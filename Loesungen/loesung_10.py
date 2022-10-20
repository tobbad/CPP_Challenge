from library import *


if __name__ == "__main__":
    print("n  bitpa encbp eVal dVal")
    for n in range(0,32):
        encg = gray_encode(n)
        decg = gray_decode(encg)
        nStr = to_binary(n)
        nStrToAsci = "%02d" % n
        encgToAsci = "%04d" % encg
        decgStrToAsci = ("%04d" % decg)
        res=("%02d "%n + nStr+" "+to_binary(n)+" "+to_binary(encg)+" "+encgToAsci+ " "+ decgStrToAsci)
        print(res)        