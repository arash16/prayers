#include <bits/stdc++.h>
#define INF 67108864
using namespace std;

int max(int X[], int n) {
	int r = X[0];
	for (int i=1; i<n; ++i)
		r = max(r, X[i]);
	return r;
}

struct State {
	int u, d;
	State(int u, int d):u(u),d(d){}
	bool operator < (const State &o) const { return d > o.d; }
};

vector<int> adj[143];
int W[143][143], D[143][143], S[143][143];
void dijkstra(int n, int src, int D[]) {
	for (int i=0; i<n; ++i)
		D[i] = INF;

	priority_queue<State> q;
	q.push(State(src, D[src]=0));
	while (!q.empty()) {
		State s = q.top(); q.pop();
		if (s.d == D[s.u])
			for (int v: adj[s.u])
				if (s.d + W[s.u][v] < D[v])
					q.push(State(v, D[v]=s.d+W[s.u][v]));
	}
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T, n, m;
	cin >> T;
	for (int cse=1; cse<=T; ++cse) {
		cout << "Map " << cse << ": ";

		cin >> n >> m;
		for (int i=0; i<n; ++i)
			adj[i].clear();

		for (int i=0, u,v,d; i<m; ++i) {
			cin >> u >> v >> d; --u; --v;
			if (S[u][v]!=cse) {
				S[u][v] = S[v][u] = cse;
				W[u][v] = W[v][u] = d;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
			else
				W[u][v] = W[v][u] = min(W[u][v], d);
		}


		dijkstra(n, 0, D[0]);
		if (max(D[0], n)==INF) cout << "-1\n";
		else {
			for (int i=1; i<5; ++i)
				dijkstra(n, i, D[i]);

			vector<int> eqd;
			for (int i=0; i<n; ++i) {
				int x = D[0][i];
				if (x==D[1][i] && x==D[2][i] && x==D[3][i] && x==D[4][i])
					eqd.push_back(i);
			}

			if (eqd.empty()) cout << "-1\n";
			else {
				int mn = INF;
				for (int i: eqd) {
					dijkstra(n, i, D[i]);
					mn = min(mn, max(D[i], n));
				}
				cout << mn << endl;
			}
		}
	}
}
