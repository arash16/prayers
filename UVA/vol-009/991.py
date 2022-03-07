##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 991
##  Name: Safe Salutations
##  Problem: https://onlinejudge.org/external/9/991.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

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
