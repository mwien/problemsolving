import sys

for line in sys.stdin:
    inv = 0
    zeros = 0
    questions = 0
    for c in reversed(line):
        if c == "0":
            zeros += 1
        if c == "1":
            if questions > 0:
                inv = (inv + pow(2, questions-1, 1000000007) * questions) % 1000000007
            inv = (inv + pow(2, questions, 1000000007) * zeros) % 1000000007
        if c == "?":
            inv = (inv * 2) % 1000000007
            if questions > 0:
                inv = (inv + pow(2, questions-1, 1000000007) * questions) % 1000000007
            inv = (inv + pow(2, questions, 1000000007) * zeros) % 1000000007
            questions += 1
    print inv
