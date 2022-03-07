/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10563
  Name: Least Squares
  Problem: https://onlinejudge.org/external/105/10563.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int n, m;
char sq[200][200];
bool isEmpty(int r, int c, int d) {
    for (int i=0; i<=d; i++)
        if (sq[r+d][c+i]!='?' || sq[r+i][c+d]!='?')
            return false;
    return true;
}

int getCharId(int i, int j) {
    if (i<0 || i>=n || j<0 || j>=m || sq[i][j]=='?' || sq[i][j]=='.')
        return -1;

    return sq[i][j]-'A';
}

char nextChar(int r, int c, int d) {
    bool used[]={0,0,0,0};
    int ind, cnt=0;
    for (int i=0; i<=d; i++) {
        ind=getCharId(r-1, c+i);
        if (ind>=0 && !used[ind]) {
            used[ind]=1;
            cnt++;
        }

        ind=getCharId(r+d+1, c+i);
        if (ind>=0 && !used[ind]) {
            used[ind]=1;
            cnt++;
        }

        ind=getCharId(r+i, c-1);
        if (ind>=0 && !used[ind]) {
            used[ind]=1;
            cnt++;
        }

        ind=getCharId(r+i, c+d+1);
        if (ind>=0 && !used[ind]) {
            used[ind]=1;
            cnt++;
        }

        if (cnt == 4) return 'E';
    }

    for (int i=0; i<4; i++)
        if (!used[i])
            return 'A'+i;
    return 'E';
}

void color(int r, int c, int d, char col) {
    for (int i=0; i<=d; i++)
        sq[r+d][c+i] = sq[r+i][c+d] = col;
}

int nextEmpty(int ij) {
    for (; ij<n*m && sq[ij/m][ij%m]!='?'; ij++);
    return ij;
}


int main(){
    bool frst=1;
    while (scanf("%d%d", &n, &m)==2 && (n||m)) {
        for (int i=0; i<n; i++)
            scanf("%s", sq[i]);

        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (sq[i][j]=='?') {
                    int bd;
                    char col = sq[i][j] = nextChar(i, j, 0);
                    for (bd=1; i+bd<n && j+bd<m && isEmpty(i, j, bd); bd++) {
                        if (nextChar(i,j,bd) > col) break;

                        int ij = nextEmpty(m*i + j + bd);
                        char ncol = ij<n*m?  nextChar(ij/m, ij%m, 0)  :'E';

                        color(i, j, bd, col);

                        char cch = nextChar(ij/m, ij%m, 0);
                        if (ij<n*m &&  (ncol!=cch || cch<col)) {
                            color(i, j, bd, '?');
                            break;
                        }
                    }
                }

        if (frst) frst=0;
        else putchar('\n');
        for (int i=0; i<n; i++)
            puts(sq[i]);
    }
}
