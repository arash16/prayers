/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 108
  Name: Maximum Sum
  Problem: https://onlinejudge.org/external/1/108.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int X[102][102], Y[102][102];

// ------ O(n^3) ------
int main(){
    int n;
    while (cin>>n) {
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++) {
                cin >> X[i][j];
                Y[i][j] = X[i][j] + Y[i-1][j];
            }

        int res = -10000;
        for (int i1=0; i1<n; i1++)
            for (int i2=i1+1; i2<=n; i2++) {
                int s = 0;
                for (int j=1; j<=n; j++) {
                    s += Y[i2][j] - Y[i1][j];
                    if (s > res) res = s;
                    if (s < 0) s = 0;
                }
            }

        cout << res << endl;
    }
}



/*
// ------ O(n^4) ------
int main(){
    int n;
    while (cin>>n) {
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++) {
                cin >> X[i][j];
                Y[i][j] = X[i][j] + Y[i-1][j] + Y[i][j-1] - Y[i-1][j-1];
            }

        int res = -10000;
        for (int i1=0; i1<n; i1++)
            for (int j1=0; j1<n; j1++)
                for (int i2=i1+1; i2<=n; i2++)
                    for (int j2=j1+1; j2<=n; j2++) {
                        int s = Y[i2][j2] - Y[i1][j2] - Y[i2][j1] + Y[i1][j1];
                        if (s > res) res = s;
                    }

        cout << res << endl;
    }
}
*/

