/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11108
  Name: Tautology
  Problem: https://onlinejudge.org/external/111/11108.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

string s;
int vals, p;
bool calc() {
    char ch = s[p++];
    switch (ch) {
        case 'p': case 'q':
        case 'r': case 's': case 't':
            return (1<<(ch-'p')) & vals;
        case 'N': return !calc();
        case 'E': return  calc() ==calc();
        case 'K': return  calc() & calc();
        case 'A': return  calc() | calc();
        case 'C': return !calc() | calc();
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> s && s[0]!='0') {
        for (vals=(1<<5)-1; vals>=0; --vals) {
            p = 0;
            if (!calc()) {
                cout << "not\n";
                goto fin;
            }
        }
        cout << "tautology\n";
        fin:;
    }
}
