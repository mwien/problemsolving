import random

print 20

for t in range(0, 20):
    S = random.randint(1, 30)
    A = random.randint(1, 30)
    m = random.randint(1, 200)
    
    print str(S) + " " + str(A) + " " + str(m)
    
    for i in range(0, m):
        print str(random.randint(1, 500)) + " " + str(random.randint(1, 500)) + " " + str(random.randint(1, 500)) + " " + str(random.randint(1, 500))
