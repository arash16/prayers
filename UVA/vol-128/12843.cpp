/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12843
  Name: Disputed Claims
  Problem: https://onlinejudge.org/external/128/12843.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int Ri[10000000], Rk[10000000];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    long long n, tn, sn, j, k2, k;
    int T;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> n;
        tn = n<<1;
        sn = sqrt(tn);

        int sz = 0;
        for (int i=1; i<=sn; ++i)
            if (tn % i == 0) {
                j = tn / i;
                k = sqrt(k2 = i*i + j*j);
                if (k*k == k2)
                    Ri[sz] = i,
                    Rk[sz] = k,
                    ++sz;
            }
        cout << "Case " << cse << ": " << sz << "\n";
        for (int i=0; i<sz; ++i)
            cout << "(" << Ri[i] << ',' << (tn/Ri[i]) << ',' << Rk[i] << ")\n";
    }
}
