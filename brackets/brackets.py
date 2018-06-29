import sys

for line in sys.stdin:
    input = line.split(" ")
    N = int(input[0])
    M = int(input[1])
    T = {}
    T[(0,0)] = 0
    T[(0,1)] = 0
    T[(0,2)] = 0
    T[(1,0)] = 0
    T[(1,1)] = 1
    T[(1,2)] = 0
    T[(2,0)] = 1
    T[(2,1)] = 0
    T[(2,2)] = 1
    for i in xrange(3, N+1):
        for j in range(0, min(N, i)+1):
            #print T
            #print i, j
            if j == 0 and i >= 2 and i-2 >= j:
                T[(i, j)] = T[(i-2, j)]
            elif j > 0 and i < 2:
                T[(i, j)] = T[(i-1, j-1)]
            elif j > 0 and i-2 >= j:
                T[(i, j)] = (T[(i-2, j)] + T[(i-1, j-1)]) % 2000000000000000000
            elif j > 0:
                T[(i, j)] = T[(i-1, j-1)]
            else:
                T[(i, j)] = 0
