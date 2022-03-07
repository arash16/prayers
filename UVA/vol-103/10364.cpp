/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10364
  Name: Square
  Problem: https://onlinejudge.org/external/103/10364.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int seen[1<<20], X[23], n, d, cse;
bool chosen[23];
bool backtrack(int s, int cnt, int state, int r) {
    if (cnt==4) return true;
    if (r == 0) return backtrack(0, cnt+1, state, d);
    if (seen[state] == cse) return false;
    seen[state] = cse;

    for (int i=s; i<n; ++i)
        if (!chosen[i] && X[i] <= r) {
            chosen[i] = 1;
            if (backtrack(i+1, cnt, state^(1<<i), r-X[i]))
                return true;
            chosen[i] = 0;
        }
    return false;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    for (cse=1; T-- && cin>>n; ++cse) {
        int sum = 0;
        for (int i=0; i<n; ++i) {
            cin >> X[i];
            sum += X[i];
        }
        sort(X, X+n, greater<int>());
        d = sum>>2;

        memset(chosen, 0, 23);
        if ((sum&3) || !backtrack(0, 0, 0, d))
            cout << "no\n";
        else
            cout << "yes\n";
    }
}
