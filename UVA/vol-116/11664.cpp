/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11664
  Name: Langton's Ant
  Problem: https://onlinejudge.org/external/116/11664.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>

int l, r;
char c[100];
bool isMod2() {
    return c[r-1]&1;
}
void shr() {
    int t = 0;
    for (int i=l; i<r; ++i) {
        t = t*10 + c[i];
        c[i] = t>>1;
        t -= c[i]<<1;
    }
    while (l<r && !c[l]) ++l;
}

char dy[] = {1, 0, -1, 0},
     dx[] = {0, -1, 0, 1};

int main() {
    int n, x, y;
    unsigned char M[20][20];
    for (int i=0; i<20; i++)
        M[i][0] = M[0][i] = 3;

    while (scanf("%d%s%d%d", &n, c, &x, &y)==4 && (n||x||y)) {
        for (l=r=0; c[r]; r++)
            c[r] -= '0';

        for (int i=n; i>0; --i) {
            M[i][n+1] = M[n+1][i] = 3;
            for (int j=n; j>0; --j) {
                M[i][j] = isMod2();
                shr();
            }
        }

        M[n][n] = 2;
        for (char d = 0; ;) {
            if (M[y][x]&2) break;
            if (M[y][x]) --d;
            else ++d;
            d = (d+4)%4;
            M[y][x] = !M[y][x];
            y += dy[d];
            x += dx[d];
        }
        puts( M[y][x] == 2 ? "Yes" : "Kaputt!");
    }
}
