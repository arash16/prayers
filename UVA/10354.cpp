#include <bits/stdc++.h>
#define INF 67108864
using namespace std;

struct State {
	int u, d;
	State(int u, int d):u(u),d(d){}
	bool operator < (const State &o) const { return d > o.d; }
};

vector<int> adj[143], P[143];
int W[143][143], D[143], S[143], n;
int dijkstra(int src, int dst) {
	if (S[src] || S[dst]) return -1;
	for (int i=1; i<=n; ++i) {
		P[i].clear();
		D[i] = INF;
	}

	priority_queue<State> q;
	q.push(State(src, D[src]=0));
	while (!q.empty()) {
		State s = q.top(); q.pop();
		if (s.d != D[s.u]) continue;
		if (s.u == dst) {
			return s.d;
		}

		for (int v: adj[s.u]) if (!S[v]) {
			int d = s.d + W[s.u][v];
			if (d <= D[v]) {
				if (d < D[v]) {
					q.push(State(v, D[v]=d));
					P[v].clear();
				}
				P[v].push_back(s.u);
			}
		}
	}
	return -1;
}

void dfs(int v) {
	S[v] = 1;
	for (int u: P[v])
		if (!S[u])
			dfs(u);
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int m, s1, d1, s2, d2;
	while (cin>>n>>m>>s1>>d1>>s2>>d2) {
		for (int i=1; i<=n; ++i) {
			adj[i].clear();
			S[i] = 0;
		}

		for (int i=0, u,v,d; i<m; ++i) {
			cin >> u >> v >> d;
			adj[u].push_back(v);
			adj[v].push_back(u);
			W[u][v] = W[v][u] = d;
		}

		if (dijkstra(s1, d1) >= 0)
			dfs(d1);

		int r = dijkstra(s2, d2);
		if (r < 0) cout << "MISSION IMPOSSIBLE.\n";
		else cout << r << endl;
	}
}
