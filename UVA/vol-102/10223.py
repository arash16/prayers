dp = [1]
for i in range(1, 22):
    dp.append( (4*i-2)*dp[i-1]//(i+1) )

import sys
for line in sys.stdin:
    for n in line.split():
        print(dp.index(int(n), 1))
