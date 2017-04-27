#include <bits/stdc++.h>
using namespace std;

int dist[1002];
vector<int> adj[1002];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int n, m; cin>>n>>m;
		for (int i=0; i<n; ++i)
			adj[i].clear();
		
		for (int i=0; i<m; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		memset(dist+1, -1, n*sizeof(int));
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v: adj[u])
				if (dist[v] < 0) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
		}
		for (int i=1; i<n; ++i)
			cout << dist[i] << endl;
		if (T) cout << endl;
	}
}
