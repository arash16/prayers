#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

list<int> childs[10001];
int par[10001], tush[10001];

int findRoot(int n) {
	for (int i=0; i<n; i++)
		if (par[i] == -1)
			return i;

	return 0;
}

int dfs(int u) {
	int cnt=0;
	for (int v: childs[u]) 
		cnt += dfs(v);

	int extra = tush[u] - 1;
	if (extra) {
		tush[par[u]] += extra;
		cnt += extra<0 ? -extra : extra;
	}
	return cnt;
}

int main(){
	int n, m, u, v;
	while (cin>>n && n) {
		for (int i=0; i<n; i++) {
			childs[i].clear();
			par[i]=-1;
		}

		for (int i=0; i<n; i++) {
			cin>> u; u--;
			cin >> tush[u] >> m;
			for (int i=0; i<m; i++) {
				cin >> v; v--;
				childs[u].push_back(v);
				par[v] = u;
			}
		}

		int root = findRoot(n);
		cout << dfs(root) << endl;
	}
}
