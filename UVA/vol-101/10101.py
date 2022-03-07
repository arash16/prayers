##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 10101
##  Name: Bangla Numbers
##  Problem: https://onlinejudge.org/external/101/10101.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

from sys import stdin, stdout

lens = [10, 100, 100, 100]
names = ['shata', 'hajar', 'lakh', 'kuti']

def conv(x):
  xx = x % 100
  res = str(xx) if xx > 0 else ''
  x = int(x / 100)

  i = 0
  unsaid = 0
  while (x > 0):
    l = lens[i]
    xx = x % l
    x = int(x / l)
    if xx > 0:
      res = str(xx) + ' ' + names[i] + (' ' + res if len(res)>0 else '')
    elif i == 3:
      res = 'kuti' + (' ' + res if len(res)>0 else '')

    i = (i + 1) % 4

  return res if len(res) > 0 else '0'

for i, x in enumerate(stdin.read().split()):
    stdout.write(format(i + 1, '4') + '. ' + conv(int(x)) + '\n')

