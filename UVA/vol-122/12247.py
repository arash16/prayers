from itertools import zip_longest, chain
from sys import stdin, stdout
I = list(map(int, stdin.read().split()))


for a,b,c,x,y in zip_longest(*([iter(I)]*5)):
  if not a: break

  princes = [a,b,c]
  xd = min(chain([100], (t for t in princes if t > x)))
  yd = min(chain([100], (t for t in princes if t > y and t != xd)))
  if xd != 100 and yd != 100:
    stdout.write('-1\n')
  elif xd == 100 and yd == 100:
    rems = set(range(1,53))-set([a,b,c,x,y])
    stdout.write('{}\n'.format(min(rems)))
  else:
    pm = max(set(princes)-set([xd, yd]))
    rems = set(range(1,53))-set([a,b,c,x,y])
    res = min(chain([100], (t for t in rems if t > pm)))
    stdout.write('{}\n'.format(res if res < 100 else -1))
