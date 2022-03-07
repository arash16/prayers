/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12428
  Name: Enemy at the Gates
  Problem: https://onlinejudge.org/external/124/12428.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


bool check(long long n, long long m) {
    return m>=n-1 && m<=(n*(n-1)>>1);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        long long n, m;
        cin >> n >> m;
        int lo=0, hi=n-1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(n-mid, m-mid))
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        cout << lo-1 << '\n';
    }
}
