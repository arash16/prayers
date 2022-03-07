/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10827
  Name: Maximum sum on a torus
  Problem: https://onlinejudge.org/external/108/10827.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;

int X[155][155], C[155][155], n;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T; cin >> T;
    while (T--) {
        cin >> n;
        int bs = -INF;
        for (int i=1; i<=n; ++i)
            for (int j=0, x; j<n; ++j) {
                cin >> x;
                bs = max(bs, X[i][j] = X[i+n][j] = X[i][j+n] = X[i+n][j+n] = x);
            }

        if (bs > 0) {
            int tn = n<<1;
            for (int j=0; j<tn; ++j)
                for (int i=1; i<=tn; ++i)
                    C[i][j] = C[i-1][j] + X[i][j];

            for (int i1=0; i1<n; ++i1)
                for (int i2=i1+1; i2-i1<=n; ++i2) {
                    int sum = 0, lj=-1;
                    for (int j=lj+1; j<tn; ++j) {
                        bs = max(bs, sum += C[i2][j] - C[i1][j]);
                        if (sum < 0) {
                            sum = 0;
                            lj = j;
                        }

                        if (j - lj == n) {
                            int nj = ++lj;
                            sum -= C[i2][lj] - C[i1][lj];

                            int tsum=0, mns=0;
                            for (int k=lj+1; k<j; ++k) {
                                tsum += C[i2][k] - C[i1][k];
                                if (tsum < mns) {
                                    mns = tsum;
                                    nj = k;
                                }
                            }
                            sum -= mns;
                            lj = nj;
                        }
                    }
                }
        }
        cout << bs << endl;
    }
}
