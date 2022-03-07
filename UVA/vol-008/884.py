##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 884
##  Name: Factorial Factors
##  Problem: https://onlinejudge.org/external/8/884.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

import math
def factors(n):
    sq = math.sqrt(n)
    cnt = 0
    i = 2
    while i <= sq:
        if n%i == 0:
            while n%i==0:
                cnt += 1
                n /= i
            sq = math.sqrt(n)+1
        i+=1
    if n > 1:
        cnt += 1
    return cnt

C = [0]
for i in range(1, 1000001):
    print(i)
    C.append(C[i-1] + factors(i))

import sys
for line in sys.stdin:
    for n in line.split():
        print(C[int(n)])
