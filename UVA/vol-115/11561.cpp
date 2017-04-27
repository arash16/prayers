#include <bits/stdc++.h>
using namespace std;


char M[55][55];
int dy[]={0,1,0,-1},
    dx[]={1,0,-1,0};
int dfs(int y, int x) {
    if (M[y][x] == '#') return 0;
    int r = M[y][x] == 'G';
    M[y][x] = '#';

    for (int k=0; k<4; ++k)
        if (M[y+dy[k]][x+dx[k]] == 'T')
            return r;

    for (int k=0; k<4; ++k)
        r += dfs(y+dy[k], x+dx[k]);

    return r;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m;
    while (cin>>m>>n) {
        for (int i=0; i<n; ++i)
            cin >> M[i];

        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (M[i][j] == 'P') {
                    cout << dfs(i, j) << endl;
                    goto fin;
                }
        fin:;
    }
}
