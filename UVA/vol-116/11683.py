from sys import stdin, stdout
I = list(map(int, stdin.read().split()))

s = 0
while s < len(I) - 2:
  [h, w] = I[s:s+2]
  if not h and not w: break
  c = I[s+2:s+2+w] + [h]

  r = 0
  for i in range(1, w+1):
    if c[i] > c[i-1]:
      r += c[i] - c[i-1]

  stdout.write('{}\n'.format(r))
  s += w + 2

