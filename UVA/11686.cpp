#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

#define MAXN 1000001
list<int> adj[MAXN];
bool seen[MAXN], inside[MAXN];
int order[MAXN], ocnt;
bool topo(int u) {
	seen[u] = 
	inside[u] = true;

	for (int v: adj[u])
		if (!seen[v]) {

			if (!topo(v)) return 0;
		}
		else if (inside[v])
			return 0;

	inside[u] = false;
	order[--ocnt] = u;
	return 1;
}


int main(){
	int n, m, u, v;
	while (cin>>n>>m && (n||m)) {
		for (int i=0; i<n; i++) {
			inside[i] = seen[i] = 0;
			adj[i].clear();
		}

		for (int i=0; i<m; i++) {
			cin>>u>>v;
			adj[u-1].push_back(v-1);
		}

		ocnt=n;
		bool f = true;
		for (int i=0; f && i<n; i++)
			if (!seen[i])
				if (!topo(i))
					f=false;


		if (!f) puts("IMPOSSIBLE");
		else {
			for (int i=0; i<n; i++)
				cout << order[i]+1 << endl;
		}
	}
}
