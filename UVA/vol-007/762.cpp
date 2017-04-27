#include <bits/stdc++.h>
using namespace std;


vector<int> adj[1000];
bool seen[1000];
int fid[1000], pre[1000], cse;
int readid() {
    char s[5];
    cin >> s;
    int u = (s[0]-'A')*26 + s[1]-'A';
    if (fid[u] != cse) {
        seen[u] = 0;
        fid[u] = cse;
        adj[u].clear();
    }
    return u;
}

void printid(int id) {
    cout << char((id/26)+'A')
         << char((id%26)+'A');
}

void printpath(int src, int dst) {
    if (src == dst) return;
    printpath(src, pre[dst]);
    printid(pre[dst]);
    cout << ' ';
    printid(dst);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int m;
    for (;cin >> m; ++cse) {
        if (cse) cout << endl;
        for (int i=0; i<m; ++i) {
            int u = readid(),
                v = readid();

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src = readid(),
            dst = readid();
        queue<int> q;
        q.push(src);
        seen[src] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v: adj[u])
                if (!seen[v]) {
                    seen[v] = 1;
                    pre[v] = u;

                    if (v == dst) {
                        printpath(src, dst);
                        goto fin;
                    }
                    q.push(v);
                }
        }

        cout << "No route\n";
        fin:;
    }
}
