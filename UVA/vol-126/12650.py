from sys import stdin, stdout
I = list(map(int, stdin.read().split()))
s = 0

while s < len(I):
  [n, r] = I[s:s+2]
  R = I[s+2: s+2+r]
  s += 2 + r

  NR = set(range(1,n+1)) - set(R)
  if not len(NR):
    stdout.write('*\n')
  else:
    NR = list(NR)
    NR.sort()
    for p in NR:
      stdout.write('{} '.format(p))
    stdout.write('\n')
