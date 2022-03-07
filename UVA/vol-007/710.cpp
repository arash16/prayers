/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 710
  Name: The Game
  Problem: https://onlinejudge.org/external/7/710.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


bool inRange(int x, int l, int r) { return x>=l && x<r; }

char M[143][143];
int S[143][143], cse, w, h,
    Qx[6116], Qy[6116], Qd[6116],
    dx[] = { 1, -1, 0, 0 },
    dy[] = { 0, 0, 1, -1 };
int bfs(int sx, int sy, int tx, int ty) {
    int qsz=1, qi=0;
    Qx[0]=sx; Qy[0]=sy;
    while (qi < qsz) {
        int x = Qx[qi], y = Qy[qi], d = Qd[qi];
        for (int dir=0; dir<4; ++dir)
            for (int k=1; ; ++k) {
                int nx = x + k*dx[dir],
                    ny = y + k*dy[dir];

                if (nx==tx && ny==ty) return d+1;
                if (!inRange(nx, 0, w) || !inRange(ny, 0, h) || M[ny][nx]=='X') break;
                if (S[ny][nx] == cse) continue;
                    S[ny][nx]  = cse;
                Qx[qsz] = nx;
                Qy[qsz] = ny;
                Qd[qsz++] = d + 1;
            }
        ++qi;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int x1, y1, x2, y2;
    for (int brd=1; cin>>w>>h && (w||h); ++brd) {
        cin.ignore(100, '\n');
        for (int i=1; i<=h; ++i) {
            cin.getline(M[i]+1, 143);
            for (int j=strlen(M[i]+1)+1; j<=w; ++j)
                M[i][j] = ' ';
            M[i][0] = M[i][w+1] = ' ';
            M[i][w+2] = 0;
        }
        w+=2; h+=2;
        memset(M[0], ' ', w); M[0][w]=0;
        memset(M[h-1], ' ', w); M[h-1][w]=0;

        cout << "Board #" << brd << ":\n";
        for (int gme=1; cin>>x1>>y1>>x2>>y2 && (x1||y1||x2||y2); ++gme) {
            cout << "Pair " << gme << ": "; ++cse;
            int result = bfs(x1, y1, x2, y2);
            if (result < 0) cout << "impossible.\n";
            else cout << result << " segments.\n";
        }
        cout << '\n';
    }
}
