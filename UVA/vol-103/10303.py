##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 10303
##  Name: How Many Trees?
##  Problem: https://onlinejudge.org/external/103/10303.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

import sys;


dp = [1]
for i in range(1, 1003):
    dp.append((4*i-2)*dp[i-1]//(i+1))

for line in sys.stdin:
    print(dp[int(line.strip())])
