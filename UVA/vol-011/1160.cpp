#include <bits/stdc++.h>
using namespace std;

int frn[100017], par[100017], cse;
int find(int u) { return par[u]<0 ? u : par[u]=find(par[u]); }
bool join(int u, int v) {
	if ((u=find(u)) != (v=find(v))) {
		if (par[v] < par[u])
			swap(u, v);

		par[u] += par[v];
		par[v] = u;
		return 1;
	}
	return 0;
}

void init(int u) {
	if (frn[u] != cse) {
		frn[u] = cse;
		par[u] = -1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int cnt = 0, u, v;
	for (cse=1; cin>>u; )
		if (u < 0) {
			cout << cnt << endl;
			cnt = 0;
			++cse;
		}
		else {
			cin >> v;
			init(u); init(v);
			if (!join(u, v)) 
				++cnt;
		}
}
