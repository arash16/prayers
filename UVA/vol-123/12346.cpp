/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12346
  Name: Water Gate Management
  Problem: https://onlinejudge.org/external/123/12346.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;


typedef long long int Int;
Int F[23], C[23], S[23], v, t, n, best;
void bt(int idx, Int cost, Int sum) {
    if (cost >= best || (sum+S[idx])*t < v) return;
    if (sum*t >= v) { best = cost; return; }
    if (idx == n) return;

    bt(idx+1, cost + C[idx], sum + F[idx]);
    bt(idx+1, cost, sum);
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> F[i] >> C[i];

    for (int i=n-1; i>=0; --i)
        S[i] = S[i+1] + F[i];

    int T; cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> v >> t;
        best = INF;
        bt(0, 0, 0);

        cout << "Case " << cse << ": ";
        if (best == INF) cout << "IMPOSSIBLE\n";
        else cout << best << '\n';
    }
}
