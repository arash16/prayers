/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 452
  Name: Project Scheduling
  Problem: https://onlinejudge.org/external/4/452.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int X[43], M[43];
vector<int> adj[43];
int dfs(int u) {
    if (M[u] != -1)
        return M[u];

    int mx = 0;
    for (int v: adj[u])
        mx = max(mx, dfs(v));

    return M[u] = mx + X[u];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char line[1000], p[43], ch;
    int T, t;
    cin >> T;
    cin.ignore(10, '\n');
    cin.ignore(10, '\n');
    while (T--) {
        for (int i=0; i<26; ++i) {
            adj[i].clear();
            X[i] = 0;
            M[i] = -1;
        }

        while (cin.getline(line, 1000) && (ch=line[0])>='A') {
            int i = 1;
            while (line[i]==' ') ++i;

            t = 0;
            while (line[i]>='0') t = t*10 + line[i++] - '0';
            while (line[i]==' ') ++i;
            X[ch-'A'] = t;

            while (line[i])
                adj[ch-'A'].push_back(line[i++]-'A');
        }

        int result = 0;
        for (int i=0; i<26; ++i)
            result = max(result, dfs(i));

        cout << result << '\n';
        if (T) cout << '\n';
    }
}
