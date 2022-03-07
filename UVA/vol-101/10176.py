##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 10176
##  Name: Ocean Deep! - Make it shallow!!
##  Problem: https://onlinejudge.org/external/101/10176.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

import sys
str = ''
for line in sys.stdin:
    str += line.strip()
    if len(str)>0 and str[-1] == '#':
        num = int(str[:-1], 2)
        if num%131071 == 0:
            print("YES")
        else:
            print("NO")
        str = ''
