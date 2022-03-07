/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11195
  Name: Another n-Queen Problem
  Problem: https://onlinejudge.org/external/111/11195.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int F[16], C[17], bitn1, n;
int backtrack(int row, int lf, int mf, int rf) {
    if (row == n) return 1;
    if (mf & C[row]) return 0;

    int result = 0;
    int fr = F[row] & lf & mf & rf;
    while (fr) {
        int pos = fr & -fr;
        fr ^= pos;
        result += backtrack(row+1, (lf^pos)<<1|1, mf^pos, (rf^pos)>>1|bitn1);
    }
    return result;
}


int main() {
    string str;
    for (int cse=1; cin >> n && n; ++cse) {
        for (int i=0; i<n; ++i) {
            F[i] = 0;
            cin >> str;
            for (int j=0; j<n; ++j)
                if (str[j] == '.')
                    F[i] |= 1 << j;
        }

        C[n] = (1<<n) - 1;
        for (int i=n-1; i>=0; --i)
            C[i] = C[i+1] & ~F[i];

        bitn1 = 1 << (n-1);
        cout << "Case " << cse << ": " << backtrack(0, C[n], C[n], C[n]) << '\n';
    }
}
