##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 10140
##  Name: Prime Distance
##  Problem: https://onlinejudge.org/external/101/10140.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

from sys import stdin, stdout
from math import sqrt

isp = [True] * 46350
isp[0] = isp[1] = False
primes = []

for i in range(2, 46350):
  if isp[i]:
    primes.append(i)
    for j in range(i+i, 46350, i):
      isp[j] = False

def isPrime(x):
  if x < 46350:
    return isp[x]

  mx = int(sqrt(x))
  for p in primes:
    if p > mx: return True
    if x % p == 0: return False
  return True

def nextPrime(x, mx):
  for p in range(x, mx+1):
    if isPrime(p):
      return p
  return -1


inp = stdin.read().split()
for x in range(0, len(inp), 2):
  L = int(inp[x])
  R = int(inp[x+1])

  mn = 0
  mx = 1e7
  i = nextPrime(L, R)
  while i < R and i > 0:
    j = nextPrime(i+1, R)
    if j < 0: break

    if j-i > mn:
      mn = j-i
      bi = i
      bj = j
    if j-i < mx:
      mx = j-i
      ai = i
      aj = j
    i = j

  if mn == 0:
    stdout.write('There are no adjacent primes.\n')
  else:
    stdout.write('{},{} are closest, {},{} are most distant.\n'.format(ai, aj, bi, bj))

