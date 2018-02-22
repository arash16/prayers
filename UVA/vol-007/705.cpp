#include <bits/stdc++.h>
using namespace std;

int ni[2][4] = {
    { 1, 0, -1, 0 },
    { -1, 0, 1, 0 }
};

int nj[2][4] = {
    { 0, -1, 0, 1 },
    { 0, 1, 0, -1 }
};

int nd[2][4] = {
    { 3, 2, 1, 0 },
    { 1, 0, 3, 2 }
};

int pos[2][4] = {
    { 0, 0, 1, 1 },
    { 1, 0, 0, 1 }
};

int w, h;
bool M[77][77], S[77][77][2];
int dfs(int si, int sj) {
    int dir=0, cnt=0, i=si, j=sj;
    while (i>=0 && i<h && j>=0 && j<w) {
        bool t = M[i][j],
             p = pos[t][dir];

        if (S[i][j][p])
            return i==si && j==sj ? cnt : 0;

        S[i][j][p] = 1;

        i += ni[t][dir];
        j += nj[t][dir];
        dir = nd[t][dir];
        ++cnt;
    }

    return 0;
}

int main() {
    for (int cse=1; cin >> w >> h && (w || h); ++cse) {
        memset(M, 0, sizeof(M));
        memset(S, 0, sizeof(S));
        for (int i=0; i<h; ++i) {
            cin.ignore(100, '\n');
            for (int j=0; j<w; ++j)
                M[i][j] = getchar() == '/';
        }

        int mx = 0, cnt = 0;
        for (int si=0; si<h; ++si)
            for (int sj=0; sj<w; ++sj)
                if (!S[si][sj][M[si][sj]]) {
                    int len = dfs(si, sj);
                    if (len) {
                        cnt++;
                        mx = max(mx, len);
                    }
                }

        cout << "Maze #" << cse << ":\n";
        if (!cnt) cout << "There are no cycles.\n";
        else cout << cnt << " Cycles; the longest has length " << mx << ".\n";
        cout << endl;
    }
}
