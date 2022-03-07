/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 722
  Name: Lakes
  Problem: https://onlinejudge.org/external/7/722.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXN 1000
char M[MAXN][MAXN];
int n, m;

int dfs(int r, int c){
    if (r<0 || r>=n || c<0 || c>=m || M[r][c]=='1') return 0;
    M[r][c] = '1';

    return dfs(r+1,c) + dfs(r-1, c) + dfs(r, c+1) + dfs(r, c-1) + 1;
}

int main(){
    int T, r, c;
    cin>>T;
    while (T--) {
        cin>>r>>c;
        cin.getline(M[0], MAXN);
        for (n=0; cin.getline(M[n], MAXN) && (M[n][0]=='1' || M[n][0]=='0'); n++);
        m = strlen(M[0]);

        cout << dfs(r-1, c-1) << endl;
        if (T) putchar('\n');
    }
}
