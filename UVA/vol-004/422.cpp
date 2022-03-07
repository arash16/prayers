/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 422
  Name: Word-Search Wonder
  Problem: https://onlinejudge.org/external/4/422.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    char X[143][143];
    for (int i=0; i<n; ++i)
        cin >> X[i];

    string s;
    while (cin >> s && s != "0") {
        int l = s.length();
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                for (int di=-1; di<2; ++di)
                for (int dj=-1; dj<2; ++dj)
                if (di>0 || dj) {
                    int ei = i + (l-1) * di,
                        ej = j + (l-1) * dj;

                    if (ei>=0 && ei<n && ej>=0 && ej<n) {
                        for (int k=0; k<l; ++k)
                            if (X[i+k*di][j+k*dj] != s[k])
                                goto not_this;

                        cout << i+1 << ',' << j+1 << ' ' << ei+1 << ',' << ej+1 << '\n';
                        goto found;
                    }
                    not_this:;
                }
        cout << "Not found\n";
        found:;
    }
}
