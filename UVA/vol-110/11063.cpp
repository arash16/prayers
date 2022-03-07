/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11063
  Name: B2-Sequence
  Problem: https://onlinejudge.org/external/110/11063.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


bool check(int X[], int n) {
    bool seen[20143] = {};
    for (int i=0; i<n; ++i) {
        if (X[i] < 1) return false;

        if (i > 0 && X[i] <= X[i-1])
            return false;

        for (int j=0; j<=i; ++j)
            if (seen[X[i]+X[j]])
                return false;
            else
                seen[X[i]+X[j]] = true;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int X[143];
    for (int cse=1, n; cin>>n; ++cse) {
        cout << "Case #" << cse;

        for (int i=0; i<n; ++i)
            cin >> X[i];

        if (check(X, n))
            cout << ": It is a B2-Sequence.\n\n";
        else
            cout << ": It is not a B2-Sequence.\n\n";
    }
}
