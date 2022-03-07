/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 13206
  Name: Beautiful Triad
  Problem: https://onlinejudge.org/external/132/13206.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


long long calc(long long l) {
    return 3*(l-1)*(l-1) + 3*(l-1) + 1;
}

int main() {
    int T, n, k;
    cin >> T;
    while (T-- && cin >> n >> k) {
        long long cnt = 0;
        if (n >= k)
            cnt += (n-k+1) * calc(k+1);

        for (int i=1; i<=k; ++i)
            cnt += calc(i);

        cout << cnt << endl;
    }
}
