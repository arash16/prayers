##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 10023
##  Name: Square root
##  Problem: https://onlinejudge.org/external/100/10023.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

from math import sqrt
import sys

_1_50 = 1 << 50  # 2**50 == 1,125,899,906,842,624
def isqrt(n):
    if n <= 1:
        return n
    if n < _1_50:
        return int(sqrt(n))

    # Make a high initial estimate of the result (a little lower is slower!!!)
    r = 1 << ((n.bit_length() + 1) >> 1)
    while True:
        newr = (r + n // r) >> 1  # next estimate by Newton-Raphson
        if newr >= r:
            return r
        r = newr

sys.stdin.readline()

sec=False
for line in sys.stdin:
  for n in line.split():
    if sec:
      print("")
    sec=True
    print(isqrt(int(n)))
