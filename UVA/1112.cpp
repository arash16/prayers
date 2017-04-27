#include <bits/stdc++.h>
using namespace std;

struct UD {
	int u, d;
	UD(int u, int d):u(u), d(d){}
	bool operator < (const UD& u) const { return d > u.d; }
};


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	vector<UD> adj[117];
	bool S[117];
	int u, v, tm;
	int T; cin >> T;
	while (T--) {
		int n, m, t, s;
		cin >> n >> s >> t >> m;

		for (int i=0; i<n; ++i) {
			adj[i].clear();
			S[i] = 0;
		}

		for (int i=0; i<m; ++i) {
			cin >> u >> v >> tm;
			adj[v-1].push_back(UD(u-1, tm));
		}

		priority_queue<UD> q;
		q.push(UD(s-1, 0));
		int cnt = 0;
		while (!q.empty()) {
			UD ud = q.top(); q.pop();
			int u = ud.u;
			if (S[u]) continue;
			S[u] = ++cnt;

			for (UD vd: adj[u]) if (!S[vd.u]) {
				int v = vd.u;
				UD tt(v, ud.d+vd.d);
				if (tt.d <= t)
					q.push(tt);
			}
		}
		cout << cnt << endl;
		if (T) cout << endl;
	}
}
