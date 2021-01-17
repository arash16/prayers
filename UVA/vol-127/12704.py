from sys import stdin, stdout
I = list(map(int, stdin.read().split()))

for i in range(0, I[0]):
  [x, y, r] = I[3*i + 1: 3*i + 4]
  cd = (x*x + y*y) ** 0.5
  stdout.write('{:.2f} {:.2f}\n'.format(r-cd, r+cd))

