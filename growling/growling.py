import sys


def main():
    t = int(sys.stdin.readline())
    for i in xrange(t):
        n = int(sys.stdin.readline())
        maxnom = -1
        maxde = 1
        for j in xrange(n):
            a, b, c = sys.stdin.readline().split()
            a = int(a)
            b = int(b)
            c = int(c)
            nom = b*b + 4*a*c
            de = 4*a
            if nom * maxde > de * maxnom:
                maxnom = nom
                maxde = de
                idx = j + 1
        print idx

if __name__ == "__main__":
    main()
