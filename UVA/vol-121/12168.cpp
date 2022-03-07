/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12168
  Name: Cat vs. Dog
  Problem: https://onlinejudge.org/external/121/12168.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[555];
int match[555];
bool seen[555];
bool bpm(int u) {
    for (int v: adj[u])
        if (!seen[v]) {
            seen[v] = 1;
            if (match[v]==-1 || bpm(match[v])) {
                match[v] = u;
                return true;
            }
        }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string X[555], Y[555];
    int T, c, d, n;
    cin >> T;
    while (T-- && cin >> c >> d >> n) {
        vector<int> L, R;
        for (int i=0; i<n; ++i) {
            adj[i].clear();
            match[i] = -1;

            cin >> X[i] >> Y[i];
            if (X[i][0] == 'C')
                L.push_back(i);
            else
                R.push_back(i);
        }

        for (int i=0; i<L.size(); ++i)
            for (int j=0; j<R.size(); ++j)
                if (X[L[i]]==Y[R[j]] || Y[L[i]]==X[R[j]])
                    adj[i].push_back(j);

        int cnt = 0;
        for (int i=0; i<L.size(); ++i) {
            memset(seen, 0, R.size());
            if (bpm(i)) ++cnt;
        }
        cout << (n-cnt) << '\n';
    }
}
