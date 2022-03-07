##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 10268
##  Name: 498-bis
##  Problem: https://onlinejudge.org/external/102/10268.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

from sys import stdin, stdout
from itertools import zip_longest

for n1, n2 in zip_longest(*([iter(stdin)]*2)):
  if not n1 or not n2: break
  x = int(n1.strip())
  a = list(map(int, n2.strip().split()))
  n = len(a)-1

  r = 0
  for i in range(0, n):
    r = r*x + a[i]*(n-i)

  stdout.write('{}\n'.format(r))

