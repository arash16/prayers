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
