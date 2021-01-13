from sys import stdin, stdout

def calc(x):
  hx = x / 2
  sum = (hx-1)*(3*hx-1)
  if x % 2: sum += 0.25
  return int((x-2)*(x-1) - sum)

res = [0,0,0,0]
for i in range(4, 1000001):
  res.append(res[i-1] + calc(i))

for n in stdin.read().split():
  if int(n) < 3: break
  stdout.write(str(res[int(n)]) + '\n')

