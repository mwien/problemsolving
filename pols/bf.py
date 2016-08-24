import sys

G = [[1, 1, 1, 1, 1, 1, 1], [0, 1, 2, 3, 4, 5, 6], [0, 1, 4, 2, 2, 4, 1], [0, 1, 1, 6, 1, 6, 6]]
comp = [2, 2, 3, 5, 1, 6, 3]
for i in range(pow(7, 4)):
    num = []
    tmp = []
    for j in range(4):
        num.append(i % 7)
        i /= 7
    for j in range(7):
        s = 0
        for k in range(4):
            s += num[k] * G[k][j]
            s = s % 7
        tmp.append(s)
    cnt = 0
    for k in range(7):
        if comp[k] != tmp[k]:
            cnt += 1
    if cnt <= 1:
        print tmp
    #sys.stdout.write(str(s) + " ")
    #sys.stdout.write("\n")
