/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1198
  Name: The Geodetic Set Problem
  Problem: https://onlinejudge.org/external/11/1198.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 67108864
using namespace std;


long long P[43][43];
int D[43][43];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string line;
    int n, m;
    cin >> n; cin.ignore(100, '\n');

    for (int u=0; u<n; ++u) {
        for (int v=0; v<n; ++v)
            D[u][v] = INF;
        D[u][u] = 0;
    }

    for (int u=0; u<n; ++u) {
        getline(cin, line);
        stringstream sin(line);

        for (int v; sin>>v; )
            if (D[u][--v]==INF)
                D[u][v] = 1;
    }

    for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
        if (i!=k && D[i][k] != INF)
            for (int j=0; j<n; ++j)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            for (int k=0; k<n; ++k)
                if (D[i][j] == D[i][k] + D[k][j])
                    P[i][j] |= 1LL << k;

    long long bsf = (1LL<<n)-1;
    cin >> m; cin.ignore(100, '\n');
    while (m--) {
        getline(cin, line);
        stringstream sin(line);
        vector<int> s;
        for (int v; sin>>v;)
            s.push_back(v-1);

        long long bs = 0;
        for (int i=0; i<s.size(); ++i)
            for (int j=0; j<=i; ++j)
                bs |= P[s[i]][s[j]];

        cout << (bs==bsf ? "yes\n" : "no\n");
    }
}
