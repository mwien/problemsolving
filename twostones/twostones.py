import sys

for line in sys.stdin:
    N = int(line)
    if N % 2 == 1:
        print "Alice"
    else:
        print "Bob"
