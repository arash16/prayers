/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10094
  Name: Place the Guards
  Problem: https://onlinejudge.org/external/100/10094.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int R[1024];
void fillQueens(int n) {
    if (n&1) {
        R[n] = n;
        fillQueens(n-1);
        return;
    }

    int hn = n>>1;
    if (n%6 != 2)
        for (int i=1; i<=hn; ++i)
            R[i] = 2*i,
            R[hn + i] = 2*i-1;

    else if (n%6 != 0)
        for (int i=1; i<=hn; ++i)
            R[i] = 1 + (2*i + hn - 3)%n,
            R[n+1-i] = n - (2*i + hn - 3)%n;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while (cin >> n) {
        if (n == 2 || n == 3)
            cout << "Impossible\n";

        else {
            fillQueens(n);
            cout << R[1];
            for (int i=2; i<=n; ++i)
                cout << ' ' << R[i];
            cout << '\n';
        }
    }
}
