/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11452
  Name: Dancing the Cheeky-Cheeky
  Problem: https://onlinejudge.org/external/114/11452.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    char str[2048];
    while (T-- && cin >> str) {
        int l = 1, i;
        for (i=1; str[i]; ++i) {
            if (str[i] != str[i%l]) {
                while (str[i] != str[i%l])
                    ++l;
                i = l;
            }
        }

        for (int j=0; j<8; ++j, ++i)
            cout << str[i%l];
        cout << "...\n";
    }
}
