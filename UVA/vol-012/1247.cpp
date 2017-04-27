#include <bits/stdc++.h>
#define INF 1073741824
using namespace std;

int D[26][26]={}, L[26][26], P[26][26];
void printPath(int u, int v) {
    if (P[u][v] == u) {
        cout << char(u+'A') << ' ';
        return;
    }
    printPath(u, P[u][v]);
    printPath(P[u][v], v);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char c1, c2;
    for (int n, m; cin >> n >> m; ) {
        for (int i=0; i<26; ++i) {
            for (int j=0; j<26; ++j) {
                P[i][j] = i;
                D[i][j] = L[i][j] = INF;
            }
            D[i][i] = 0;
        }

        for (int i=0; i<m; ++i) {
            int d;
            cin >> c1 >> c2 >> d;
            c1 -= 'A'; c2 -= 'A';
            D[c1][c2] = D[c2][c1] = d;
            L[c1][c2] = L[c2][c1] = 1;
            P[c1][c2] = c1;
            P[c2][c1] = c2;
        }

        for (int k=0; k<26; ++k)
            for (int i=0; i<26; ++i)
            if (i!=k && D[i][k]!=INF)
                for (int j=0; j<26; ++j)
                if (j!=k && D[j][k]!=INF) {
                    int d = D[i][k] + D[k][j],
                        l = L[i][k] + L[k][j];

                    if (d < D[i][j] || (d==D[i][j] && l < L[i][j])) {
                        D[i][j] = d;
                        L[i][j] = l;
                        P[i][j] = k;
                    }
                }

        cin >> m;
        while (m--) {
            cin >> c1 >> c2;
            printPath(c1-'A', c2-'A');
            cout << c2 << endl;
        }
    }
}
