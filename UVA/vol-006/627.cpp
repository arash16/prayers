#include <bits/stdc++.h>
using namespace std;

bool seen[1001];
int pre[1001];
vector<int> adj[1001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    string str;
    while (cin >> n) {
        for (int i=0, u; i<n; ++i) {
            cin >> str;
            stringstream sin(str);
            sin >> u;
            adj[u].clear();
            for (int v; sin.ignore(1); )
                if (sin>>v)
                    adj[u].push_back(v);
        }

        cout << "-----\n";
        int q; cin >> q;
        while (q--) {
            int src, dst;
            cin >> src >> dst;
            memset(seen, 0, n+1);
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
                            stack<int> st;
                            for (int p=v; p!=src; p=pre[p])
                                st.push(p);
                            cout << src;
                            for (; !st.empty(); st.pop())
                                cout << ' ' << st.top();
                            cout << endl;
                            goto fin;
                        }
                        q.push(v);
                    }
            }
            cout << "connection impossible\n";
            fin:;
        }
    }
}
