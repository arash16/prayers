/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11456
  Name: Trainsorting
  Problem: https://onlinejudge.org/external/114/11456.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int X[2086], I[2086], D[2086], M[2086], n;
int LIS(bool comp(int, int), int R[]) {
    int L = 0;
    for (int i=0; i<n; ++i) {
        int lo=1, hi=L;
        while (lo <= hi) {
            int mid = (lo+hi)>>1;
            if (comp(X[M[mid]], X[i]))
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        M[R[i] = lo] = i;
        L = max(L, lo);
    }
    return L;
}

bool isLt(int a, int b) { return a < b; }
bool isGt(int a, int b) { return a > b; }
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=0; i<n; ++i)
            cin >> X[n-i-1];

        LIS(isLt, I);
        LIS(isGt, D);

        int mx = 0;
        for (int i=0; i<n; ++i)
            mx = max(mx, I[i]+D[i]-1);
        cout << mx << endl;
    }
}
