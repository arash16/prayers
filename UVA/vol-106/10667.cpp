#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);


    bool B[143][143];
    int T, n, m, C[143];
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i=0; i<n; ++i)
            memset(B[i], 0, n);

        for (int r1,r2,c1,c2; m--; ) {
            cin >> r1 >> c1 >> r2 >> c2;
            for(int i=r1-1; i<r2; ++i)
                for (int j=c1-1; j<c2; ++j)
                    B[i][j] = 1;
        }

        int ms = 0;
        for (int i1=0; i1<n; ++i1) {
            memset(C, 0, n*sizeof(int));
            for (int i2=i1; i2<n; ++i2) {
                int sum = 0;
                for (int j=0; j<n; ++j) {
                    C[j] = C[j]<0 || B[i2][j] ? -1 : C[j]+1;
                    if (C[j] != -1)
                         ms = max(ms, sum += C[j]);
                    else sum = 0;
                }
            }
        }
        cout << ms << endl;
    }
}
