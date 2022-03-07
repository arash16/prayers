/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1209
  Name: Wordfish
  Problem: https://onlinejudge.org/external/12/1209.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int mdist(string str) {
    int d = 1000;
    for (int i=1; i<str.length(); ++i)
        d = min(d, abs(str[i] - str[i-1]));
    return d;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string s1;
    while (cin>>s1) {
        string s2 = s1, bs = s1;
        int d = mdist(s1);
        for (int i=0; i<10 && prev_permutation(s1.begin(), s1.end()); ++i) {
            int t = mdist(s1);
            if (t >= d) {
                bs = s1;
                d = t;
            }
        }

        for (int i=0; i<10 && next_permutation(s2.begin(), s2.end()); ++i) {
            int t = mdist(s2);
            if (t > d) {
                bs = s2;
                d = t;
            }
        }

        cout << bs << d << endl;
    }
}
