/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 435
  Name: Block Voting
  Problem: https://onlinejudge.org/external/4/435.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int DP[1024], X[23], n, T;
    cin >> T;
    while (T-- && cin>>n) {
        int sum = 0;
        for (int i=0; i<n; ++i) {
            cin >> X[i];
            sum += X[i];
        }

        int hs = sum>>1;
        for (int i=0; i<n; ++i) {
            memset(DP, 0, (hs+1)*sizeof(int));
            DP[0] = 1;
            for (int j=0; j<n; ++j)
                if (j != i)
                for (int k=hs-X[j]; k>=0; --k)
                    DP[k + X[j]] += DP[k];

            int r = 0;
            for (int k=hs-X[i]+1; k<=hs; ++k)
                r += DP[k];

            printf("party %d has power index %d\n", i+1, r);
        }
        cout << endl;
    }
}
