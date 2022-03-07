/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10651
  Name: Pebble Solitaire
  Problem: https://onlinejudge.org/external/106/10651.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int DP[4096];
int rec(int state) {
    if (!state) return 0;
    if (DP[state]) return DP[state];

    int result = 1000;
    for (int i=0, x=state; x && i<10; ++i, x>>=1) {
        int t = x&7;
        if (t == 3 || t == 6)
            result = min(result, rec(state ^ (7 << i)));
    }

    if (result == 1000) {
        result = 0;
        for (; state; state>>=1)
            result += state&1;
    }
    return DP[state]=result;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    string line;
    while (T-- && cin >> line) {
        int num = 0;
        for (int i=0; i<12; ++i)
            num = num<<1 | (line[i]=='o');

        cout << rec(num) << '\n';
    }
}
