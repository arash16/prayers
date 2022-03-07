/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11230
  Name: Annoying painting tool
  Problem: https://onlinejudge.org/external/112/11230.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


char M[101][101];
int n, m, r, c;
int solve() {
    int cnt = 0;
    bool R[101][101] = {};
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (R[i][j] != M[i][j]-'0') {
                if (i+r>n || j+c>m) return -1;
                for (int di=0; di<r; ++di)
                    for (int dj=0; dj<c; ++dj)
                        R[i+di][j+dj] = !R[i+di][j+dj];
                ++cnt;
            }
    return cnt;
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> n >> m >> r >> c && (n||m||r||c)) {
        for (int i=0; i<n; ++i)
            cin >> M[i];

        cout << solve() << '\n';
    }
}
