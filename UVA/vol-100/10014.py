##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 10014
##  Name: Simple calculations
##  Problem: https://onlinejudge.org/external/100/10014.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

from sys import stdin, stdout
inp = stdin.read().split()

s = 1
T = int(inp[0])
for cse in range(0, T):
  if cse > 0: stdout.write('\n')

  n = int(inp[s])
  a = float(inp[s+1])
  b = float(inp[s+2])
  c = list(map(float, inp[s+3:s+3+n]))
  s += n + 3

  res = (n*a + b - sum(2 * (n-i) * c for i,c in enumerate(c))) / (n+1)
  stdout.write('{:.2f}\n'.format(res))

