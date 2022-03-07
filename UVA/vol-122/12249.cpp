/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12249
  Name: Overlapping Scenes
  Problem: https://onlinejudge.org/external/122/12249.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


string merge(const string &s1, const string &s2) {
    int l1 = s1.length(),
        l2 = s2.length();
    for (int i=min(l1, l2); i>0; --i)
        if (s1.substr(l1-i, i) == s2.substr(0, i))
            return s1 + s2.substr(i, l2-i);
    return s1 + s2;
}

int n, best;
string S[7];
bool used[7];
void bt(int cnt, const string bb) {
    if (bb.length() >= best) return;
    if (cnt == n) {
        best = bb.length();
        return;
    }

    for (int i=0; i<n; ++i)
        if (!used[i]) {
            used[i] = 1;
            bt(cnt+1, merge(bb, S[i]));
            used[i] = 0;
        }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> n;
        for (int i=0; i<n; ++i)
            cin >> S[i];

        best = (int)1e9;
        bt(0, "");
        cout << "Case " << cse << ": " << best << '\n';
    }
}
