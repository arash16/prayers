from sys import stdin, stdout

dp = [0, 1]
max_pre = 673366
for i in range(2, max_pre):
  dp.append(1 + dp[i - dp[dp[i-1]]])

def f(n):
  if n < max_pre:
    return dp[n]

  i = j = 1
  while True:
    ni = i + dp[j] * dp[dp[j]]
    if ni < n:
      i = ni
      j += dp[dp[j]]
    else:
      return j + int((n-i)/dp[j])

for n in stdin.read().split():
  if int(n) == 0: break
  stdout.write('{}\n'.format(f(int(n))))

