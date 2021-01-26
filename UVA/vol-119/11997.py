from heapq import heapify, heappush, heappop
from sys import stdin, stdout

I = list(map(int, stdin.read().split()))
ii = 0

while ii < len(I):
  N = I[ii]

  sums = I[ii+1: ii+1 + N]
  sums.sort()

  for k in range(1, N):
    X = I[ii+1 + k*N: ii+1 + k*N + N]
    X.sort()

    q = list(-(s + X[0]) for s in sums)
    heapify(q)

    for s in sums:
      for j in range(1, N):
        if s + X[j] < -q[0]:
          heappop(q)
          heappush(q, -(s + X[j]))
        else: break

    for i in range(0, N):
      sums[N-i-1] = -heappop(q)

  stdout.write(' '.join(map(str, sums)) + '\n')
  ii += N*N + 1
