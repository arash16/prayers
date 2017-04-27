#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int X[30], Y[30], DP[30][30];

int main(){
    int n, t;
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>t;
        X[t] = i;
    }

    while (cin>>t) {
        Y[t]=1;
        for (int i=2; i<=n; i++) {
            cin>>t;
            Y[t]=i;
        }

        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                if (X[i] == Y[j])
                    DP[i][j] = DP[i-1][j-1] + 1;
                else
                    DP[i][j] = max(DP[i-1][j], DP[i][j-1]);

        cout << DP[n][n] << endl;
    }
}
