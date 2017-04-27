#include <bits/stdc++.h>
#define INF 1073741824
using namespace std;

struct State {
	int u, d;
	State(){}
	State(int u, int d):u(u),d(d){}
	bool operator < (const State& e) const { return d > e.d; }
};

vector<State> adj[43];
int D[43], pre[43];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int n, src, dst;
	for (int cse=1; cin >> n && n; ++cse) {
		cout << "Case " << cse << ": Path =";

		for (int i=1, m; i<=n; ++i) {
			cin >> m;
			adj[i].resize(m);
			for (int j=0; j<m; ++j)
				cin >> adj[i][j].u >> adj[i][j].d;
			D[i] = INF;
		}

		cin >> src >> dst;
		priority_queue<State> q;
		q.push(State(src, D[src]=0));
		while (!q.empty()) {
			State s = q.top(); q.pop();
			if (s.d != D[s.u]) continue;
			if (s.u == dst) {
				stack<int> st;
				for (int u=s.u; u!=src; u=pre[u])
					st.push(u);
				st.push(src);
				while (!st.empty()) {
					cout << ' ' << st.top();
					st.pop();
				}
				cout << "; " << s.d << " second delay\n";
				break;
			}

			for (State vd: adj[s.u])
				if (s.d + vd.d < D[vd.u]) {
					q.push(State(vd.u, D[vd.u]=s.d + vd.d));
					pre[vd.u] = s.u;
				}
		}
	}
}
