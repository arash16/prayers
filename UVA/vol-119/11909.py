from sys import stdin, stdout
from itertools import zip_longest
import math

for l,w,h,t in zip_longest(*[iter(map(int, stdin.read().split()))]*4):
  r = math.pi * t / 180
  o = l * math.tan(r)
  if o <= h:
    s = l*h - l*o/2
  else:
    r = math.pi/2 - r
    o = h * math.tan(r)
    s = h * o / 2

  stdout.write('{:.3f} mL\n'.format(w * s))

