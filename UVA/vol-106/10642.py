##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 10642
##  Name: Can You Solve It?
##  Problem: https://onlinejudge.org/external/106/10642.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

from sys import stdin, stdout

def num(x, y):
  return (x+y)*(x+y+1)//2 + x + 1

I = list(map(int, stdin.read().split()))
for cse in range(1, I[0]+1):
  s = 4 * cse - 3
  r = num(I[s+2], I[s+3]) - num(I[s], I[s+1])
  stdout.write('Case {}: {}\n'.format(cse, r))

