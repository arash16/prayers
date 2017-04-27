#include <bits/stdc++.h>
#define INF 67108864
using namespace std;

struct State {
    int u, d;
    State(int u, int d):u(u),d(d){}
    bool operator < (const State &o) const { return d > o.d; }
};

int W1[26][26], W2[26][26], D1[26], D2[26];
vector<int> adj1[26], adj2[26];

void connect(vector<int> adj[26], int W[][26], int x, int y, int d) {
    adj[x].push_back(y);
    W[x][y] = d;
}

void dijkstra(int n, int src, const vector<int> adj[26], int W[][26], int D[]) {
    for (int i=0; i<n; ++i)
        D[i] = INF;

    priority_queue<State> q;
    q.push(State(src, D[src]=0));
    while (!q.empty()) {
        State s = q.top(); q.pop();
        if (s.d != D[s.u]) continue;

        for (int v: adj[s.u])
            if (s.d + W[s.u][v] < D[v])
                q.push(State(v, D[v]=s.d + W[s.u][v]));
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int m;
    char src;
    while (cin >> m && m) {
        for (int i=0; i<26; ++i) {
            adj1[i].clear();
            adj2[i].clear();
        }

        for (int i=0, d; i<m; ++i) {
            char t, di, x, y;
            cin >> t >> di >> x >> y >> d;
            x -= 'A'; y -= 'A';

            if (t == 'Y') connect(adj1, W1, x, y, d);
            else connect(adj2, W2, x, y, d);

            if (di == 'B')
                if (t == 'Y') connect(adj1, W1, y, x, d);
                else connect(adj2, W2, y, x, d);
        }

        cin >> src;
        dijkstra(26, src-'A', adj1, W1, D1);

        cin >> src;
        dijkstra(26, src-'A', adj2, W2, D2);

        int mnd = INF;
        for (int i=0; i<26; ++i)
            mnd = min(mnd, D1[i]+D2[i]);

        if (mnd == INF)
            cout << "You will never meet.\n";

        else {
            cout << mnd;
            for (int i=0; i<26; ++i)
                if (D1[i]+D2[i] == mnd)
                    cout << ' ' << char(i+'A');
            cout << endl;
        }
    }
}
