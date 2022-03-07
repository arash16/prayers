/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11961
  Name: DNA
  Problem: https://onlinejudge.org/external/119/11961.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


vector<string> res;
char E[] = "ACGT", str[17];
void dfs(int idx, int cnt) {
    if (!str[idx] || !cnt) {
        res.push_back(str);
        return;
    }

    char o = str[idx];
    for (int i=0; i<4; ++i) {
        str[idx] = E[i];
        dfs(idx+1, cnt - (E[i] != o));
    }
    str[idx] = o;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, c;
    cin >> T;
    while (T-- && cin >> n >> c >> str) {
        res.clear();
        dfs(0, c);
        cout << res.size() << '\n';
        for (const string &s: res)
            cout << s << '\n';
    }
}
