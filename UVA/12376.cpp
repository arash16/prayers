#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

int val[102];
list<int> adj[102];

int main(){
	int T, n, m;
	cin>>T;
	for (int cse=1; cse<=T; cse++) {
		cin>>n>>m;
		for (int i=0; i<n; i++) {
			adj[i].clear();
			cin>>val[i];
		}

		for (int i=0; i<m; i++) {
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
		}

		int tv=0, u=0;
		while (!adj[u].empty()) {
			int bv=0;
			for (int v: adj[u])
				if (val[v] >= val[bv])
					bv = v;
			tv += val[u = bv];
		}

		printf("Case %d: %d %d\n", cse, tv, u);
	}
}
