import sys

list = []
for line in sys.stdin:
    list.append(int(line))
list = list[1:]
table = [0] * 11
cnt = 0
for i in range(50):
    for j in range(50):
        for k in range(50):
            if i == j or j == k or i == k:
                continue
            if list[i] + list[j] == list[k]:
                cnt += 1
                table[list[k]] += 1
print cnt
print table
print list
