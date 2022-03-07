##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 10223
##  Name: How many nodes ?
##  Problem: https://onlinejudge.org/external/102/10223.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

dp = [1]
for i in range(1, 22):
    dp.append( (4*i-2)*dp[i-1]//(i+1) )

import sys
for line in sys.stdin:
    for n in line.split():
        print(dp.index(int(n), 1))
