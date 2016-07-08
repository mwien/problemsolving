import sys
import random

N = random.randint(3, 30)
print N
adj = [[0 for i in range(N)] for j in range(N)]
l = [sys.maxsize] * (N*N)
for i in range(30):
    l[i] = random.randint(1, 100)
random.shuffle(l)
for i in range(N):
    for j in range(N):
        if i == j:
            sys.stdout.write(str(0) + " ")
            continue
        adj[i][j] = l[i*N + j]
        if adj[i][j] == sys.maxsize:
            sys.stdout.write(str(-1) + " ")
        else:
            sys.stdout.write(str(adj[i][j]) + " ")
    print

for k in range(N):
    for i in range(N):
        for j in range(N):
            if adj[i][k] == sys.maxsize or adj[k][j] == sys.maxsize:
                continue
            if(adj[i][j] > adj[i][k] + adj[k][j]):
                adj[i][j] = adj[i][k] + adj[k][j]

K = random.randint(1, 100)
print K
for i in range(K):
    while True:
        a = random.randint(0, N/2-1)
        b = random.randint(N/2, N-1)
        if adj[a][b] != sys.maxsize:
            break
    sys.stdout.write(str(a))
    sys.stdout.write(str(b))
    print random.randint(adj[a][b], 2*adj[a][b])

Q = 100
print Q
for i in range(Q):
    while True:
        a = random.randint(0, N/2-1)
        b = random.randint(N/2, N-1)
        if adj[a][b] != sys.maxsize:
            break
    sys.stdout.write(str(a))
    sys.stdout.write(str(b))
    print

