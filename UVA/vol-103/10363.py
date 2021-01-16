from sys import stdin, stdout

def check(B):
  # Horizontals
  if any(B[i] != '.' and B[i] == B[i+1] and B[i] == B[i+2] for i in range(0, 7, 3)):
    return True

  # Verticals
  if any(B[i] != '.' and B[i] == B[i+3] and B[i] == B[i+6] for i in range(0, 3, 1)):
    return True

  # Diagonals
  if (B[0] != '.' and B[0] == B[4] and B[0] == B[8]) or (B[2] != '.' and B[2] == B[4] and B[2] == B[6]):
    return True

  return False

valids = set()
def bf(B, p):
  s = ''.join(B)
  if s in valids: return

  valids.add(s)
  if check(B): return

  for i in range(0, 9):
    if B[i] == '.':
      B[i] = p
      bf(B, 'X' if p == 'O' else 'O')
      B[i] = '.'

bf(list('.........'), 'X')

inp = stdin.read().split()
for i in range(0, 3 * int(inp[0]), 3):
  B = inp[i+1]+inp[i+2]+inp[i+3]
  stdout.write('yes\n' if B in valids else 'no\n')

