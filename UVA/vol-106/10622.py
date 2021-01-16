from sys import stdin, stdout

def pp(n):
  sgn = 1
  if n < 0:
    sgn = -1
    n = -n

  for i in range(32, 1, -1):
    if i % 2 == 0 and sgn < 0: continue
    sq = int(n ** (1/i))
    if sq**i == n or (sq+1)**i == n:
      return i
  return 1

for n in stdin.read().split():
  if not int(n): break
  stdout.write('{}\n'.format(pp(int(n))))

