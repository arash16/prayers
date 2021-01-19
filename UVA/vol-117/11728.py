from sys import stdin, stdout

res = [-1] * 1001
for n in range(1, 1001):
  sf = sum(i + (n//i if i*i != n else 0) for i in range(1, int(n**0.5)+1) if n % i == 0)
  if sf < 1001:
    res[sf] = max(res[sf], n)

for cse, n in enumerate(stdin.read().split()):
  if int(n):
    stdout.write('Case {}: {}\n'.format(cse+1, res[int(n)]))

