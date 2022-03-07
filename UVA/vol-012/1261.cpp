/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1261
  Name: String Popping
  Problem: https://onlinejudge.org/external/12/1261.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


unordered_map<string, int> DP;
bool dfs(string s) {
    int len = s.length();
    if (!len) return 1;

    auto it = DP.find(s);
    if (it != DP.end())
        return it->second;

    for (int i=0; i<len; ++i)
        if (s[i]=='1') {
            string ss = !i ? s.substr(1, string::npos) :
                        i==len-1 ? s.substr(0, i) :
                        s.substr(0, i-1) + "1" + s.substr(i+2, string::npos);
            if (dfs(ss)) return DP[s]=1;
        }
    return DP[s]=0;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        string str, ss;
        cin >> str;
        for (int i=1, k=1; i<=str.length(); ++i)
            if (str[i] != str[i-1]) {
                ss += k>1 ? "1" : "0";
                k = 1;
            }
            else ++k;

        cout << dfs(ss) << endl;
    }
}
