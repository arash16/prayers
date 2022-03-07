/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 384
  Name: Slurpys
  Problem: https://onlinejudge.org/external/3/384.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int pos;
string str;
bool slump() {
    if (str[pos]!='D' && str[pos]!='E') return 0;
    if (str[++pos] != 'F') return 0;
    while (str[++pos] == 'F');
    if (str[pos] == 'G') return ++pos;
    return slump();
}

bool slimp() {
    if (str[pos]!='A') return 0;
    if (str[++pos]=='H') return ++pos;
    if (str[pos]=='B') {
        ++pos;
        if (!slimp())
            return 0;
    }
    else if (!slump())
        return 0;
    return str[pos++]=='C';
}

bool slurpy() {
    return slimp() && slump() && pos==str.length();
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    cout << "SLURPYS OUTPUT\n";
    while (T--) {
        pos = 0;
        cin >> str;
        cout << (slurpy() ? "YES\n" : "NO\n");
    }
    cout << "END OF OUTPUT\n";
}
