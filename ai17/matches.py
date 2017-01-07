import sys

def score(x, y, n, m):
    if x >= n or y >= m:
        return 0
    elif x in (0, n-1) and y in (0, m-1):
        return 2
    elif x in (0, n-1) or y in (0, m-1):
        return 1
    else:
        return 0

def calc(i, c, p):
    if c == 'f':
        j = 0
        v = 4
    if c == 's':
        j = 1
        v = 6
    if c == 't':
        j = 2
        v = 8
    res = 1
    for x in range (v-i):
        res *= (1-p)
    for x in range(j):
        res *= p
    return res
    
q = int(input().strip())
for a0 in range(q):
    n,m,p = input().strip().split(' ')
    n,m,p = [int(n),int(m),float(p)]
    f = [0]*5
    s = [0]*7
    t = [0]*9
    
    f[0] = max(n-2, 0) * max(m-2, 0)
    s[0] = max(m-2, 0) * max(n-3, 0) + max(m-3, 0) * max(n-2, 0)
    t[0] = max(m-3, 0)*max(n-3, 0)*4 + max(m-4, 0)* max(n-2, 0) + max(n-4, 0) * max(m-2, 0)
    nup = min(2, n-1)
    mup = min(2, m-1)
    for i in range(n):
        sc = score(i, 0, n, m)
        f[sc] += 2
    for i in range(1,m-1):
        sc = score(0, i, n, m)
        f[sc] += 2
    for i in range(n):
        sc = score(i, 0, n, m)
        s[sc+score(i, 1, n, m)] += mup
        if i < n-1:
            s[sc+score(i+1, 0, n, m)] += 2
    for i in range(1, m-1):
        sc = score(0, i, n, m)
        if nup >= 1:
            s[sc+score(1, i, n, m)] += nup
        if i < m-2:
            s[sc+score(0, i+1, n, m)] += 2
    for i in range(n):
        sc = score(i, 0, n, m)
        if m == 3:
            t[sc + score(i, 1, n, m) + score(i, 2, n, m)] += 1
        elif m >= 4:
            t[sc + score(i, 1, n, m) + score(i, 2, n, m)] += 1
        if i < n-2:
            t[sc + score(i+1, 0, n, m) + score(i+2, 0, n, m)] += 2
    for i in range(n):
        if mup < 1:
            break
        sc = score(i, 0, n, m)
        sc += score(i, 1, n, m)
        if i > 0:
            t[sc + score(i-1, 0, n, m)] += 2
        if i < n-1:
            t[sc + score(i+1, 0, n, m)] += 2
    for i in range(1, m-1):
        sc = score(0, i, n, m)
        if n == 3:
            t[sc + score(1, i, n, m) + score(2, i, n, m)] += 1
        elif n >= 4:
            t[sc + score(1, i, n, m) + score(2, i, n, m)] += 2
        if i < m-3:
            t[sc + score(0, i+1, n, m) + score(0, i+2, n, m)] += 2
    for i in range(1, m-1):
        if nup < 1:
            break
        sc = score(0, i, n, m)
        sc += score(1, i, n, m)
        if i > 0:
            t[sc + score(0, i-1, n, m)] += 2
        if i < m-1:
            t[sc + score(0, i+1, n, m)] += 2
    en = 0.0
    for i in range(len(f)):
        en += f[i]*calc(i, 'f', p)
    for i in range(len(s)):
        en += s[i]*calc(i, 's', p)
    for i in range(len(t)):
        en += t[i]*calc(i, 't', p)
    print(en/(n*m))
