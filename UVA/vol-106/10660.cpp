/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10660
  Name: Citizen attention offices
  Problem: https://onlinejudge.org/external/106/10660.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int D[6][5][5], R[30], C[30], P[30];
void calcs(int p, int B[5][5], int A[5][5]) {
    int r=p/5, c=p%5;
    for (int i=0; i<5; ++i)
        for (int j=0; j<5; ++j)
            A[i][j] = min(B[i][j], abs(r-i)+abs(c-j));
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    for (int i=0; i<5; ++i)
        for (int j=0; j<5; ++j)
            D[0][i][j] = (int)1e9;

    int T, n, r, c, p;
    cin >> T;
    while (T-- && cin>>n) {
        for (int i=0; i<n; ++i)
            cin >> R[i] >> C[i] >> P[i];

        char o[5], bo[5];
        int bsum = (int)1e9;
        for (o[0]=0; o[0]<25; ++o[0]) {
            calcs(o[0], D[0], D[1]);
            for (o[1]=o[0]+1; o[1]<25; ++o[1]) {
                calcs(o[1], D[1], D[2]);
                for (o[2]=o[1]+1; o[2]<25; ++o[2]) {
                    calcs(o[2], D[2], D[3]);
                    for (o[3]=o[2]+1; o[3]<25; ++o[3]) {
                        calcs(o[3], D[3], D[4]);
                        for (o[4]=o[3]+1; o[4]<25; ++o[4]) {
                            calcs(o[4], D[4], D[5]);

                            int sum = 0;
                            for (int i=0; i<n; ++i)
                                sum += P[i] * D[5][R[i]][C[i]];

                            if (bsum > sum) {
                                bsum = sum;
                                memcpy(bo, o, 5);
                            }
                        }
                    }
                }
            }
        }
        cout << int(bo[0]);
        for (int i=1; i<5; ++i)
            cout << ' ' << int(bo[i]);
        cout << '\n';
    }
}
