/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1052
  Name: Bit Compressor
  Problem: https://onlinejudge.org/external/10/1052.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int L, N;
string S;
int bt(int pos, int l, int n) {
    if (l > L || n > N) return 0;
    if (pos == S.length())
        return l==L && n==N;

    int x = S[pos]-'0';
    if (!x) return bt(pos+1, l+1, n);

    int r = S[pos+1]!='1' ? bt(pos+1, l+1, n+1) :
            S[pos+2]!='1' ? bt(pos+2, l+2, n+2) : 0;
    if (r > 1) return 2;

    for (int i=pos+1; i<S.length(); ++i) {
        x = x<<1|(S[i]-'0');
        if (l+x>L || n+x>N) break;
        if (S[i+1] != '1' && x>2) {
            r += bt(i+1, l+x, n+x);
            if (r > 1) return 2;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int cse=1; cin >> L >> N >> S; ++cse) {
        int r = N<=L ? bt(0, 0, 0) : 0;
        cout << "Case #" << cse << ": " << (!r ? "NO\n" : r < 2 ? "YES\n" : "NOT UNIQUE\n");
    }
}
