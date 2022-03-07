/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11432
  Name: Busy Programmer
  Problem: https://onlinejudge.org/external/114/11432.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    long long DP[34][77][77] = {};
    for (int g=1; g<34; ++g) {
        DP[g][0][0] = 1;
        for (int i=1; i<=66; ++i) {
            for (int j=1; j<=i; ++j) {
                DP[g][i][j] = 0;
                for (int k=min(i, g); k>0; --k)
                    DP[g][i][j] += DP[g][i-k][i-j];
            }
        }
    }

    for (int cse=1, d,g; cin >> d >> g && (d>=0 && g>=0); ++cse) {
        long long sum = 0; d <<= 1;
        for (int i=1; d-i>=0; i+=g+1)
            sum += DP[g][d-i][d>>1];

        cout << "Case " << cse << ": " << 2*sum << endl;
    }
}
