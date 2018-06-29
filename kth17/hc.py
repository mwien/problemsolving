import sys
n = int(sys.stdin.readline())
while True:
    a = (3*n*n + n)/2
    if a%4 == 0:
        break
    n = n + 1
print(n)
