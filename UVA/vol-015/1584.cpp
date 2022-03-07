/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1584
  Name: Circular Sequence
  Problem: https://onlinejudge.org/external/15/1584.pdf
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
    string str;
    while (T-- && cin>>str) {
        string best = str;
        for (int i=1; i<str.length(); ++i) {
            string o = str.substr(i, str.length()-i) + str.substr(0, i);
            if (o < best) best = o;
        }
        cout << best << endl;
    }
}
