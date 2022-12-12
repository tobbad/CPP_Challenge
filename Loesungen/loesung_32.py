from library import *

def loesung():
    opt, args = getOpt()
    line_cnt = int(args[0])
    lines = pascal_dreieck(line_cnt)
    for l in lines:
        print("%s" % l)

if __name__ == "__main__":
    loesung()
