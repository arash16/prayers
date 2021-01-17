def pdir(a, b, c):
  num = (b[0]-a[0])*(c[1]-a[1]) - (b[1]-a[1])*(c[0]-a[0])
  return 1 if num > 0 else -1 if num < 0 else 0

def isHull(n, p):
  d = pdir(p[0], p[1], p[2])
  for i in range(1, len(p)):
    if d != pdir(p[i], p[(i+1)%n], p[(i+2)%n]):
      return False
  return True

# ----------------------------------------------------

from sys import stdin, stdout
I = list(map(int, stdin.read().split()))
s = 0
while True:
  n = I[s]
  if not n: break

  p = [(I[s+2*i+1], I[s+2*i+2]) for i in range(0, n)]
  stdout.write('No\n' if isHull(n, p) else 'Yes\n')
  s += 2*n + 1

