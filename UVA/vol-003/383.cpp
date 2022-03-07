/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 383
  Name: Shipping Routes
  Problem: https://onlinejudge.org/external/3/383.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int dist[31];
    int T; cin>>T;
    cout << "SHIPPING ROUTES OUTPUT\n";
    for (int cse=1; cse<=T; ++cse) {
        int n, m, p, q;
        cin >> n >> m >> q;
        cout << "\nDATA SET  " << cse << endl << endl;

        string s1, s2;
        map<string, int> ids;
        for (int i=0; i<n; ++i) {
            cin >> s1;
            ids[s1] = i;
        }

        vector<int> adj[31];
        for (int i=0; i<m; ++i) {
            cin >> s1 >> s2;
            int u=ids[s1], v=ids[s2];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i=0; i<q; ++i) {
            cin >> p >> s1 >> s2;
            int src=ids[s1], dst=ids[s2];
            memset(dist, -1, n*sizeof(int));
            dist[src]=0;

            queue<int> q;
            q.push(src);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v: adj[u])
                    if (dist[v] < 0) {
                        dist[v] = dist[u]+1;
                        if (v == dst) goto fin;
                        q.push(v);
                    }
            }
            fin:
            if (dist[dst] < 0)
                cout << "NO SHIPMENT POSSIBLE\n";
            else
                cout << "$" << (100*p*dist[dst]) << endl;
        }
    }
    cout << "\nEND OF OUTPUT\n";
}
