##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 13190
##  Name: Rockabye Tobby
##  Problem: https://onlinejudge.org/external/131/13190.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

from heapq import heapify, heappush, heappop
from sys import stdin, stdout
I = iter(stdin.read().split())
T = int(next(I))

for cse in range(0, T):
  n = int(next(I))
  k = int(next(I))

  meds = [(next(I), int(next(I))) for i in range(0, n)]
  q = list((v, i, k) for (i, (k,v)) in enumerate(meds))
  heapify(q)
  meds = dict(meds)

  for i in range(0, k):
    m = heappop(q)
    stdout.write('{} {}\n'.format(m[0], m[2]))
    heappush(q, (m[0] + meds[m[2]], m[1], m[2]))

