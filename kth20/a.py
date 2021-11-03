import sys

def calc(n, k, cmp, flag):
    res = 1
    for i in range(n-k+1, n+1):
        res *= i
        if flag and res > cmp:
            return res
    return res

def solve(a):
    for k in range(200, 0, -1):
        lo = 2*k
        hi = a
        cmp = a * calc(k, k, -1, False)
        #print(calc(k,k))
        while lo <= hi:
            mid = (lo + hi) // 2
            #print(lo, mid, hi, k)
            b = calc(mid, k, cmp, True)
            #print(b)
            if b == cmp:
                return (mid, k)
            elif b > cmp:
                hi = mid - 1
            else:
                lo = mid + 1
        
                        

for line in sys.stdin:
    a = int(line)
    if a == 1:
        print("0 0")
    else:
        (n, k) = solve(a)
        print(n, k)
                

