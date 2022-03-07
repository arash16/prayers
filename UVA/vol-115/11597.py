##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 11597
##  Name: Spanning Subtree
##  Problem: https://onlinejudge.org/external/115/11597.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

from sys import stdin, stdout

for cse, n in enumerate(stdin.read().split()):
  if int(n):
    stdout.write('Case {}: {}\n'.format(cse+1, int(n)//2))

