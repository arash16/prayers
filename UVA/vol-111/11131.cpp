/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11131
  Name: Close Relatives
  Problem: https://onlinejudge.org/external/111/11131.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> ids;
string names[5555], line;
vector<int> adj[5555];

void dfs1(int u) {
    for (int v: adj[u])
        dfs1(v);
    cout << names[u] << '\n';
}

void dfs2(int u) {
    for (auto it=adj[u].rbegin(); it!=adj[u].rend(); ++it)
        dfs2(*it);
    cout << names[u] << '\n';
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int cnt = 1, n = 0;
    while (getline(cin, line)) {
        int u = -1;
        for (int i=0, j=0; i<=line.length(); ++i)
            if (line[i]==',' || !line[i]) {
                names[n] = line.substr(j, i-j);
                auto r = ids.emplace(names[n], n);
                if (r.second) ++n;
                if (u < 0) u = r.first->second;
                else adj[u].push_back(r.first->second);
                j = i+1;
            }
        if (u>=0 && adj[u].size()>1)
            cnt = 2;
    }

    cout << cnt << "\n\n";
    dfs1(0);
    if (cnt==2) {
        cout << '\n';
        dfs2(0);
    }
}
