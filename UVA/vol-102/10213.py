##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 10213
##  Name: How Many Pieces of Land ?
##  Problem: https://onlinejudge.org/external/102/10213.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

from sys import stdin, stdout

# f(n) = f(n-1) + sum( (i-1)*(n-1-i) , i=1..n-1 )
for n in map(int, stdin.read().split()[1:]):
  r = n*(n*(n*(n-6)+23)-18)//24 + 1
  stdout.write('{}\n'.format(r))

