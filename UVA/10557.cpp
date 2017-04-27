#include <bits/stdc++.h>
#define INF 1073741824
using namespace std;


int E[114], D[114], n;
vector<int> adj[114];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	while (cin>>n && n>0) {
		for (int i=0, d; i<n; ++i) {
			cin >> E[i] >> d;
			adj[i].resize(d);
			for (int j=0; j<d; ++j) {
				cin >> adj[i][j];
				--adj[i][j];
			}
			D[i]=0;
		}

		D[0] = 100;


		for (int i=0, som=1; som && i<=n; ++i) {
			som = 0;
			for (int u=0; u<n; ++u)
				if (D[u] > 0)
				for (int v: adj[u])
					if (D[u] + E[v] > D[v]) {
						if (v == n-1) {
							cout << "winnable\n";
							goto fin;
						}
						D[v] = i<n-1 ? D[u] + E[v] : INF;
						som = 1;
					}
		}
		cout << "hopeless\n";
		fin:;
	}
}
