/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10506
  Name: The Ouroboros problem
  Problem: https://onlinejudge.org/external/105/10506.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int n, m, nmn, rem;
char R[68000];
bool S[68000];
bool dfs(int idx, int x) {
    if (idx == nmn+m-1)
        return 1;

    if (idx >= nmn) {
        int xx = (x*n) % rem;
        if (!S[xx]) {
            S[xx] = 1;
            if (dfs(idx+1, xx))
                return 1;
            S[xx] = 0;
        }
        return 0;
    }

    for (int d=0; d<n; ++d) {
        int xx = (x*n + d) % rem;
        if (!S[xx]) {
            S[xx] = 1;
            R[idx] = '0'+d;
            if (dfs(idx+1, xx))
                return 1;
            S[xx] = 0;
        }
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> m >> n) {
        rem = pow(n, m);
        nmn = pow(n, m);
        memset(R, '0', nmn);
        R[nmn] = 0;

        memset(S, 0, sizeof(S));
        S[0] = 1;

        if (dfs(m, 0))
            cout << R << '\n';
    }
}
