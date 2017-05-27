#include <bits/stdc++.h>
using namespace std;


bool U[7];
int S[7], W[7], H[7], X[7][17], Y[7][17], n;

int M[4][4];
bool dfs(int k) {
    if (k == n) return 1;
    for (int y=0; y<=4-H[k]; ++y)
        for (int x=0; x<=4-W[k]; ++x) {
            for (int i=0; i<S[k]; ++i)
                if (M[y+Y[k][i]][x+X[k][i]])
                    goto impo;

            for (int i=0; i<S[k]; ++i)
                M[y+Y[k][i]][x+X[k][i]] = k+1;

            if (dfs(k+1)) return 1;

            for (int i=0; i<S[k]; ++i)
                M[y+Y[k][i]][x+X[k][i]] = 0;

            impo:;
        }
    return 0;
}





char BUF[1000000], ln[100];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    bool frst = 1;
    while (cin >> n && n>0) {
        if (frst) frst = 0;
        else cout << '\n';

        int co = 0;
        for (int i=0; i<n; ++i) {
            cin >> H[i] >> W[i];

            int sz = 0;
            for (int j=0; j<H[i]; ++j) {
                cin >> ln;
                for (int k=0; k<W[i]; ++k)
                    if (ln[k] == '1') {
                        Y[i][sz] = j;
                        X[i][sz] = k;
                        ++sz;
                    }
            }
            S[i] = sz;
            co += sz;
        }

        memset(M, 0, sizeof(M));
        memset(U, 0, sizeof(U));
        if (co==16 && dfs(0))
            for (int i=0; i<4; ++i) {
                for (int j=0; j<4; ++j)
                    cout << M[i][j];
                cout << '\n';
            }

        else cout << "No solution possible\n";
    }
}
