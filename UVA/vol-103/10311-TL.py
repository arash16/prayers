from sys import stdin, stdout

isP = [True] * 10143
isP[0] = isP[1] = False
primes = []
for i in range(2, 10143):
  if isP[i]:
    primes.append(i)
    for j in range(i*i, 10143, i):
      isP[j] = False


def isPrime(n):
  if n < 10143: return isP[n]
  for p in primes:
    if p*p > n: break
    if n % p == 0:
      return False
  return True


def findPrimes(n):
  if n % 2 == 1:
    return (True, 2, n-2) if isPrime(n-2) else (False, None, None)

  half = n//2 - 1
  if half % 2 == 0: half -= 1
  for i in range(half, 1, -2):
    if isPrime(i) and isPrime(n-i):
      return (True, i, n-i)

  return (False, None, None)

for n in stdin.read().split():
  isSum, p1, p2 = findPrimes(int(n))
  if isSum:
    stdout.write('{} is the sum of {} and {}.\n'.format(n, p1, p2))
  else:
    stdout.write('{} is not the sum of two primes!\n'.format(n))

