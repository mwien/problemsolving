import sys
import math

for line in sys.stdin:
    n = int(line)
    phi = n-1
    r = phi
    fac = []
    for i in range(2, int(math.sqrt(phi))+2):
        if r % i == 0:
            fac.append(i)
        while r % i == 0:
            r //= i
    if r > 1:
        fac.append(r)
    y = phi
    for i in range(len(fac)):
        y *= 1 - 1/fac[i]
    y = int(y)
    res = -1
    for i in range(2, n):
        poss = True
        for j in range(len(fac)):
            if pow(i, phi//fac[j], n) == 1:
                poss = False
                break
        if poss:
            res = i
            break
    print(i, y)
    
