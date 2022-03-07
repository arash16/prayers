/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11520
  Name: Fill the Square
  Problem: https://onlinejudge.org/external/115/11520.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> n;
        char M[12][12] = {};
        for (int i=1; i<=n; ++i)
            cin >> (M[i]+1);

        cout << "Case " << cse << ":\n";
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j)
                if (M[i][j] == '.') {
                    char ch = 'A';
                    while (M[i-1][j]==ch || M[i][j-1]==ch || M[i+1][j]==ch || M[i][j+1]==ch)
                        ++ch;
                    M[i][j] = ch;
                }
            cout << (M[i]+1) << '\n';
        }
    }
}
