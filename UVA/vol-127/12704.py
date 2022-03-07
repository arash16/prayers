##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 12704
##  Name: Little Masters
##  Problem: https://onlinejudge.org/external/127/12704.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

from sys import stdin, stdout
I = list(map(int, stdin.read().split()))

for i in range(0, I[0]):
  [x, y, r] = I[3*i + 1: 3*i + 4]
  cd = (x*x + y*y) ** 0.5
  stdout.write('{:.2f} {:.2f}\n'.format(r-cd, r+cd))

