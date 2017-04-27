#include <bits/stdc++.h>
using namespace std;


double X[1017], Y[1017];
vector<int> adj[1017];
int dist[1017];

double dist2(int i, int j) {
    double    xx = X[i]-X[j],
            yy = Y[i]-Y[j];
    return xx*xx + yy*yy;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, v, m;
    while (cin >> v >> m && (v||m)) {
        int threshold = v*m*60;
        threshold*=threshold;

        for (n=0; cin.ignore(1000, '\n'); ++n) {
            if (cin.peek() == '\n') break;
            cin >> X[n] >> Y[n];
            adj[n].clear();
            dist[n] = -1;
            for (int i=0; i<n; ++i)
                if (dist2(i, n) <= threshold) {
                    adj[i].push_back(n);
                    adj[n].push_back(i);
                }
        }


        queue<int> q;
        q.push(0);
        dist[0]=0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v: adj[u])
                if (dist[v] < 0) {
                    if (v == 1) {
                        cout << "Yes, visiting " << dist[u] << " other holes.\n";
                        goto fin;
                    }

                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
        }
        cout << "No.\n";
        fin:;
    }
}
