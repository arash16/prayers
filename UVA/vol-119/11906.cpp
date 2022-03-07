/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11906
  Name: Knight in a War Grid
  Problem: https://onlinejudge.org/external/119/11906.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

bool s[110][110], g[110][110];
int r, c, m, n, eve, odd;

int dfs(int x, int y) {
    if (x<0 || x>=r || y<0 || y>=c || g[x][y]) return 0;
    if (!s[x][y]) {
        s[x][y]=1;

        int r = 0;
        r += dfs(x+m, y+n);
        if (m)
            r += dfs(x-m, y+n);
        if (n) {
            r += dfs(x+m, y-n);
            if (m)
                r += dfs(x-m, y-n);
        }

        if (m != n) {
            r += dfs(x+n, y+m);
            if (m)
                r += dfs(x+n, y-m);
            if (n) {
                r += dfs(x-n, y+m);
                if (m)
                    r += dfs(x-n, y-m);
            }
        }

        if (r&1)
             odd++;
        else eve++;
    }
    return 1;
}

int main(){
    int T, u, v, w;
    cin>>T;
    for (int cse=1; cse<=T; cse++) {
        cin>>r>>c>>m>>n>>w;
        for (int i=0; i<r; i++)
            for (int j=0; j<c; j++)
                g[i][j]=s[i][j]=0;

        for (int i=0; i<w; i++) {
            cin>>u>>v;
            g[u][v]=1;
        }

        odd=eve=0;
        dfs(0, 0);

        printf("Case %d: %d %d\n", cse, eve, odd);
    }
}
