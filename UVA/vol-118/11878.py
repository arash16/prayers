##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 11878
##  Name: Homework Checker
##  Problem: https://onlinejudge.org/external/118/11878.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

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
