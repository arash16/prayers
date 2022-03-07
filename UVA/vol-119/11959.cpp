/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11959
  Name: Dice
  Problem: https://onlinejudge.org/external/119/11959.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

string P[64];
string rotate(string s, int a, int b, int c, int d) {
    char sa = s[a];
    s[a] = s[b];
    s[b] = s[c];
    s[c] = s[d];
    s[d] = sa;
    return s;
}

bool check(const string &s1, const string &s2) {
    for (int i=0; i<64; ++i) {
        bool f = 1;
        for (int j=0; f && j<6; ++j)
            f &= s1[j] == s2[P[i][j]-'0'];
        if (f) return 1;
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string s1 = "012345", s2;
    for (int i=0, sz=0; i<4; ++i) {
        string s2 = s1 = rotate(s1, 2, 3, 4, 5);
        for (int j=0; j<4; ++j) {
            string s3 = s2 = rotate(s2, 0, 3, 1, 5);
            for (int k=0; k<4; ++k)
                P[sz++] = s3 = rotate(s3, 2, 0, 4, 1);
        }
    }

    int T;
    cin >> T;
    while (T-- && cin>>s1>>s2)
        cout << (check(s1, s2) ? "Equal\n" : "Not Equal\n");
}
