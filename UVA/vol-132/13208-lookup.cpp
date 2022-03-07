/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 13208
  Name: Drought In Nlogonia
  Problem: https://onlinejudge.org/external/132/13208.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


long long C[10143];
int R[10143][16], H[10143], X[10143], n;
void build(int n) {
    for (int i=0; i<n; ++i)
        R[i][0] = i;

    for (int j=1, tj; (tj=1<<j) <= n; ++j)
        for (int i=0; i+tj <= n; ++i) {
            int tj1 =  1 << (j-1);
            R[i][j] = H[R[i][j-1]] > H[R[i + tj1][j-1]] ? R[i][j-1] : R[i + tj1][j-1];
        }
}

int rmq(int qs, int qe) {
    int j = (int)log2(qe-qs+1),
        i = qe - (1 << j) + 1;
    return H[R[qs][j]] > H[R[i][j]] ? R[qs][j] : R[i][j];
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, a;
    cin >> T;
    while (T-- && cin >> a >> n) {
        for (int i=1; i<=n; ++i) {
            cin >> X[i];
            C[i] = C[i-1] + X[i];
        }

        for (int j=0; j<=n; ++j)
            cin >> H[j];
        H[n+1] = -1;
        build(n+1);

        int mxi = 0;
        for (int j=1; j<=n; ++j)
            if (H[j] > H[mxi])
                mxi = j;

        long long sum = 0;
        for (int i=mxi; i<n; ) {
            int ni = rmq(i+1, n);
            sum += (C[ni]-C[i]) * min(H[i], H[ni]) * a;
            i = ni;
        }

        for (int i=mxi; i>0; ) {
            int ni = rmq(0, i-1);
            sum += (C[i]-C[ni]) * min(H[i], H[ni]) * a;
            i = ni;
        }

        cout << sum << endl;
    }
}
