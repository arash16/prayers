DP = [1]
for i in range(1, 13):
    DP.append((4*i-2)*DP[i-1]//(i+1))

import sys
frst = 1
for line in sys.stdin:
    l = line.strip()
    if len(l) > 0:
        if not frst:
            print()
        else:
            frst = 0
        print(DP[int(line)])
