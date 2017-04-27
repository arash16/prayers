#include <stdio.h>
#include <iostream>
using namespace std;

int id[]={0, 1, -1, 1, -1, 0};
int jd[]={1, 1, 0, 0, -1, -1};

#define MAXN 202
char lines[MAXN][MAXN];
bool seen[MAXN][MAXN];
int n;

bool dfs(int ii, int jj) {
    if (ii<0 || jj<0 || ii>=n || jj>=n || seen[ii][jj] || lines[ii][jj]!='w')
        return false;

    if (jj == n-1)
        return true;

    seen[ii][jj] = 1;

    for (int k=0; k<6; k++)
        if (dfs(ii+id[k], jj+jd[k]))
            return true;

    return false;
}

int main(){
    int cse=1;
    while (cin>>n && n) {
        cin.getline(lines[0], MAXN);
        for (int i=0; i<n; i++) {
            cin.getline(lines[i], MAXN);
            for (int j=0; j<n; j++)
                seen[i][j]=0;
        }

        bool ww=0;
        for (int i=0; !ww && i<n; i++)
            if (dfs(i, 0))
                ww=1;

        printf("%d %c\n", cse++, ww ? 'W' : 'B');
    }
}
