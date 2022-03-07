##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 914
##  Name: Jumping Champion
##  Problem: https://onlinejudge.org/external/9/914.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

from sys import stdin, stdout
I = list(map(int, stdin.read().split()))

primes = [2]
maxP = 1000001
isP = [True] * maxP
isP[0] = isP[1] = False
for i in range(3, maxP, 2):
  if isP[i]:
    primes.append(i)
    for j in range(i*i, maxP, i):
      isP[j] = False

for c in range(0, I[0]):
  [L, R] = I[2*c+1: 2*c+3]

  l = -1
  F = {}
  mx = 0
  mxi = -1
  isc = False
  for i, p in enumerate(primes):
    if p > R: break
    if p < L: continue
    if l != -1:
      dif = p - l
      if not dif in F:
        F[dif] = 1
      else:
        F[dif] += 1

      if F[dif] > mx:
        mx = F[dif]
        mxi = dif
        isc = True
      elif F[dif] == mx and dif != mxi:
        isc = False
    l = p

  if isc: stdout.write('The jumping champion is {}\n'.format(mxi))
  else: stdout.write('No jumping champion\n')

