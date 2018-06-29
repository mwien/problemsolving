import sys


dp = []
dp.append(1)
for i in range(1, 70):
    dp.append(dp[i-1] * 3)

for line in sys.stdin:
    n = long(line)
    if not n:
        break
    out = "{"
    n -= 1
    idx = 0
    first = True
    while n:
        cur = n % 2
        if cur and not first:
            out += ", " + str(dp[idx])
        elif cur:
            out += " " + str(dp[idx])
            first = False
        idx += 1
        n = n / 2
    out += " }"
    print out
