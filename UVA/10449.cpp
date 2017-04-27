#include <bits/stdc++.h>
#define INF 1073741824
using namespace std;


int sq3(int x) { return x*x*x; }
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	vector<int> adj[212];
	int C[212], B[212], D[212][212];
	for (int cse=1, n, m; cin>>n; ++cse) {
		cout << "Set #" << cse << endl;

		for (int i=0; i<n; ++i) {
			cin >> B[i];
			adj[i].clear();
			C[i] = INF;
		}
		C[0] = 0;

		cin >> m;
		for (int i=0, u, v; i<m; ++i) {
			cin >> u >> v; --u; --v;
			D[u][v] = sq3(B[v] - B[u]);
			adj[u].push_back(v);
		}

		for (int i=0, som=1; som-- && i<=n; ++i)
			for (int u=0; u<n; ++u)
				if (C[u] != INF)
				for (int v: adj[u]) {
					int c = C[u] + D[u][v];
					if (c < C[v]) {
						C[v] = i<n-1 ? c : -160000;
						som = 1;
					}
				}

		cin >> m;
		for (int i=0, u; i<m; ++i) {
			cin >> u; --u;

			if (C[u] < 3 || C[u]==INF) 
				cout << "?\n";
			else
				cout << C[u] << endl;
		}
	}
}
