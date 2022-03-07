/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10188
  Name: Automated Judge Script
  Problem: https://onlinejudge.org/external/101/10188.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


char S[3][23] = {
    "Accepted",
    "Presentation Error",
    "Wrong Answer"
};

int check(const string &s1, const string &s2) {
    if (s1 == s2) return 0;

    int l1 = s1.length(),
        l2 = s2.length();
    for (int i=0,j=0; i<l1 || j<l2; ++i,++j) {
        while (i<l1 && !isdigit(s1[i])) ++i;
        while (j<l2 && !isdigit(s2[j])) ++j;
        if (s1[i] != s2[j]) return 2;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int cse=1, n,m; cin >> n && n>0; ++cse) {
        string str1, str2, str;

        cin.ignore(100, '\n');
        for (int i=0; i<n; ++i)
            getline(cin, str),
            str1 += str + "\n";

        cin >> m;
        cin.ignore(100, '\n');
        for (int i=0; i<m; ++i)
            getline(cin, str),
            str2 += str + "\n";

        cout << "Run #" << cse << ": " << S[check(str1, str2)] << endl;
    }
}
