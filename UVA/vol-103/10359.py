##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 10359
##  Name: Tiling
##  Problem: https://onlinejudge.org/external/103/10359.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

DP = [1,1]
for i in range(2, 255):
    DP.append(DP[i-1] + 2*DP[i-2])

import sys
for line in sys.stdin:
  print(DP[int(line)])
