import sys

def solve(line):
    e1 = line.split("=")
    if e1[1] == "?":
        return 0
    e2 = e1[0].split("+")
    if (len(e2) == 2):
        return int(e2[0])+int(e2[1]) == int(e1[1])

    e2 = e1[0].split("-")
    return int(e2[0])-int(e2[1]) == int(e1[1])

cnt = 0
for line in sys.stdin:
    if solve(line.strip()):
        cnt += 1

print(cnt)
