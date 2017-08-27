tzo = 'imix ik akbal kan chicchan cimi manik lamat muluk ok chuen eb ben ix mem cib caban eznab canac ahau'.split()
hmn = 'pop no zip zotz tzec xul yoxkin mol chen yax zac ceh mac kankin muan pax koyab cumhu uayet'.split()
mind = dict(zip(hmn, range(20)))

n = int(input())
print(n)

for i in range(n):
    [d, m, y] = input().split()
    d = int(d[:-1])
    m = mind[m]
    x = int(y)*365 + m*20 + d
    print((x%13)+1, tzo[x%20], x//260)
