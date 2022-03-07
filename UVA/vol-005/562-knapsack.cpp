/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 562
  Name: Dividing coins
  Problem: https://onlinejudge.org/external/5/562.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int X[143], DP[143][55055], M[143][55055], cse;
bool rec(int id, int r) {
    if (!id && !r) return 1;
    if (!id) return 0;
    if (M[id][r]==cse) return DP[id][r];

    DP[id][r] = (r>=X[id] && rec(id-1, r-X[id])) || rec(id-1, r);
    M[id][r] = cse;
    return DP[id][r];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n;
    cin>>T;
    for (cse=1; cse<=T; ++cse) {
        cin>>n;

        int sum = 0;
        for (int i=1; i<=n; ++i) {
            cin >> X[i];
            sum += X[i];
        }
        int hs = sum>>1;

        /*
        dp[0][0] = 1;
        for (int i=1; i<=n; ++i)
            for (int r=0; r<=hs; ++r)
                dp[i][r] = (r>=X[i] && dp[i-1][r-X[i]]) || dp[i-1][r];
        */

        for (int r=hs; r>=0; --r)
            if (rec(n, r)) {
                cout << sum-2*r << "\n";
                break;
            }
    }
}

