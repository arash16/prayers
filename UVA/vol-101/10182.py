##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 10182
##  Name: Bee Maja
##  Problem: https://onlinejudge.org/external/101/10182.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

from sys import stdin, stdout

num = 2
i = 1
j = 0
l = 1
d = ((-1,1), (-1,0), (0,-1), (1,-1), (1,0), (0,1))
res = [[0,0]]
while num < 100143:
  for di in range(0, 6):
    for k in range(0, l):
      i += d[di][0]
      j += d[di][1]
      res.append((i, j))
      num += 1
  i += 1
  l += 1

for n in stdin.read().split():
  i = int(n) - 1
  stdout.write('{} {}\n'.format(res[i][0], res[i][1]))

