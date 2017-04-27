#include <stdio.h>
#include <iostream>
using namespace std;

int a[102], b[102], DP[102][102];
int main(){
    int n, m, cse=0;

    while (cin>>n>>m && (n||m)) {
        for (int i=1; i<=n; i++)
            cin >> a[i];

        for (int j=1; j<=m; j++) {
            cin >> b[j];
            for (int i=1; i<=n; i++)
                DP[i][j]=0;
        }

        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                if (a[i] == b[j])
                    DP[i][j] = DP[i-1][j-1] + 1;
                else if (j>0)
                    DP[i][j] = max(DP[i-1][j], DP[i][j-1]);

        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", ++cse, DP[n][m]);
    }
}
