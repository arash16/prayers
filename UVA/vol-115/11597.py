from sys import stdin, stdout

for cse, n in enumerate(stdin.read().split()):
  if int(n):
    stdout.write('Case {}: {}\n'.format(cse+1, int(n)//2))

