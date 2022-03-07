/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12626
  Name: I ❤ Pizza
  Problem: https://onlinejudge.org/external/126/12626.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

char SS[] = "MARGIT";
int CC[] = {1,3,2,1,1,1};
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    string str;
    while (T-- && cin >> str) {
        int C[91] = {};
        for (int i=0; str[i]; ++i)
            if (str[i]<91)
                ++C[str[i]];

        int mx = (int)1e9;
        for (int i=0; SS[i]; ++i)
            mx = min(mx, C[SS[i]]/CC[i]);
        cout << mx << '\n';
    }
}
