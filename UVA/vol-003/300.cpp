/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 300
  Name: Maya Calendar
  Problem: https://onlinejudge.org/external/3/300.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

char tzo[20][20] = {
    "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok",
    "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
};

char hmn[19][19] = {
    "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax",
    "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
};


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    map<string, int> mind;
    for (int i=0; i<19; ++i)
        mind[hmn[i]] = i;

    int n,d,y;
    cin >> n;
    cout << n << endl;
    while (n--) {
        char ch, s[100];
        cin >> d >> ch >> s >> y;
        int m = mind[s];
        int x = y*365 + m*20 + d;
        cout << (x%13)+1 << ' ' << tzo[x%20] << ' ' << x/260 << endl;
    }
}
