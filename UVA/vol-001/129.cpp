/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 129
  Name: Krypton Factor
  Problem: https://onlinejudge.org/external/1/129.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


char str[88];
bool check(int len) {
    for (int l=len>>1; l>0; --l) {
        for (int i=len-l, j=len-2*l; i<len; ++i, ++j)
            if (str[i] != str[j])
                goto next_len;
        return 0;
        next_len:;
    }
    return 1;
}

int maxch;
vector<string> vec[26];
bool dfs(int idx=0) {
    if (idx >= 80) return 0;

    for (char ch=0; ch<=maxch; ++ch) {
        str[idx] = 'A' + ch;
        if (check(idx+1)) {
            str[idx+1] = 0;
            vec[maxch].push_back(str);
            if (!dfs(idx+1)) return 0;
        }
    }
    return 1;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    for (maxch=0; maxch<26; ++maxch) dfs(0);

    int n, l;
    while (cin >> n >> l && (n||l)) {
        string s = vec[l-1][n-1];
        cout << s[0];
        for (int i=1; s[i]; ++i) {
            if (i%64 == 0)
                cout << '\n';
            else if (i%4 == 0)
                cout << ' ';
            cout << s[i];
        }
        cout << '\n' << s.length() << '\n';
    }
}
