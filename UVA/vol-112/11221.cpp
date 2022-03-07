/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11221
  Name: Magic square palindromes.
  Problem: https://onlinejudge.org/external/112/11221.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


char M[143][143];
bool check(char *s, int sz) {
    for (int i=0; s[i]; ++i)
        M[i/sz][i%sz] = s[i];

    for (int i=0; i<sz; ++i)
        for (int j=0; j<sz; ++j) {
            char ch = M[i][j];
            if (ch!=M[j][i] || ch!=M[sz-i-1][sz-j-1] || ch!=M[sz-j-1][sz-i-1])
                return 0;
        }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    cin.ignore(100, '\n');

    char str[10143];
    for (int cse=1; cse<=T; ++cse) {
        cout << "Case #" << cse << ":\n";

        cin.getline(str, 10143);
        int l = 0;
        for (int i=0; str[i]; ++i)
            if (isalpha(str[i]))
                str[l++] = str[i];
        str[l] = 0;

        int sq = sqrt(l);
        if (sq*sq == l && check(str, sq))
            cout << sq << '\n';
        else
            cout << "No magic :(\n";
    }
}
