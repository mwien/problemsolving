import sys
c = 299792458
for line in sys.stdin:
    m = int(line)
    print m*c*c
