##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 11385
##  Name: Da Vinci Code
##  Problem: https://onlinejudge.org/external/113/11385.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

import re
from sys import stdin, stdout

a = 1
b = 2
F = { 1: 0, 2: 1 }
for i in range(2, 45):
  r = a + b
  a = b
  b = r
  F[r] = i

for cse in range(0, int(next(stdin))):
  N = int(next(stdin))
  p = list(map(int, next(stdin).split()))
  s = re.sub(r'[^A-Z]+', '', next(stdin).strip())

  r = [' '] * max(F[i]+1 for i in p)
  for i, x in enumerate(p):
    if x in F:
      r[F[x]] = s[i]

  stdout.write(''.join(r).rstrip() + '\n')

