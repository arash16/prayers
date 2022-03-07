/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10460
  Name: Find the Permuted String
  Problem: https://onlinejudge.org/external/104/10460.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


long long F[43];
char S[43], P[43], n;
void bt(int idx, int ind) {
    if (idx == n) {
        if (ind > 0) cout << "E: ";
        cout << P << '\n';
        return;
    }

    long long ff = 1;
    for (int j=idx+2; j<=n && ff<=ind; ++j) ff *= j;

    int i = 0;
    while (i<idx && ind-ff >= 0) ind -= ff, ++i;
    for (int j=idx; j>i; --j) P[j] = P[j-1];

    P[i] = S[idx];
    bt(idx+1, ind);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    memset(F, 127, sizeof(F));
    F[1] = 1;
    for (int i=2; i<16; ++i)
        F[i] = F[i-1] * i;

    int T, ind;
    cin >> T;
    while (T--) {
        cin.ignore(100, '\n');
        cin.getline(S, 43);
        cin >> ind;
        P[n = strlen(S)] = 0;

        bt(0, ind-1);
    }
}
