/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11110
  Name: Equidivisions
  Problem: https://onlinejudge.org/external/111/11110.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int n; char A[120][120];
int dfs(int y, int x, char c) {
    if (A[y][x] != c) return 0;
    A[y][x] = -1;
    int r = 1;

    if (x > 0) r += dfs(y, x-1, c);
    if (x<n-1) r += dfs(y, x+1, c);
    if (y > 0) r += dfs(y-1, x, c);
    if (y<n-1) r += dfs(y+1, x, c);
    return r;
}

bool seen[101];
bool check() {
    memset(seen, 0, n);
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (A[i][j]>=0) {
                if (seen[A[i][j]])
                    return 0;
                else {
                    seen[A[i][j]] = 1;
                    dfs(i, j, A[i][j]);
                }
            }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string line;
    while (cin >> n && n) {
        for (int i=0; i<n; ++i)
            memset(A[i], 0, n);

        cin.ignore(500, '\n');
        for (int i=1, x, y; i<n; ++i) {
            getline(cin, line);
            stringstream sin(line);
            while (sin>>y>>x)
                A[y-1][x-1] = i;
        }

        cout << (check() ? "good\n" : "wrong\n");
    }
}
