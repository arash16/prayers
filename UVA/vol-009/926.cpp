/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 926
  Name: Walking Around Wisely
  Problem: https://onlinejudge.org/external/9/926.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    long long C[43][43];
    bool BR[43][43], BU[43][43];
    int T, n, m, si, sj, ei, ej;
    cin >> T;
    while (T--) {
        cin >> n
            >> sj>>si >> ej>>ei
            >> m;

        for (int i=0; i<=n; ++i)
            memset(BR[i], 0, n+1),
            memset(BU[i], 0, n+1),
            memset(C[i], 0, (n+1)*sizeof(long long));

        for (int i=0, bi,bj; i<m; ++i) {
            char dir;
            cin >> bj >> bi >> dir;
            switch(dir) {
                case 'E': BR[bi][bj] = 1; break;
                case 'N': BU[bi][bj] = 1; break;
                case 'W': BR[bi][bj-1] = 1; break;
                case 'S': BU[bi-1][bj] = 1; break;
            }
        }

        C[si][sj] = 1;
        for (int i=si; i<=ei; ++i)
            for (int j=sj; j<=ej; ++j) {
                if (!BR[i][j])
                    C[i][j+1] += C[i][j];

                if (!BU[i][j])
                    C[i+1][j] += C[i][j];
            }

        cout << C[ei][ej] << endl;
    }
}
