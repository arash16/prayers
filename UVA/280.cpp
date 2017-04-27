#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;


list<int> adj[110];
int seen[110], cnt;
void dfs(int u) {
	if (seen[u]) return;
	seen[u] = 1; cnt++;

	for (int v: adj[u])
		dfs(v);
}


int main() {
	int n, u, v, t;
	while (cin>>n && n) {
		for (int i=1; i<=n; i++)
			adj[i].clear();

		while (cin>>u && u)
			while (cin>>v && v)
				adj[u].push_back(v);
				
		
		cin >> t;
		for (int i=0; i<t; i++) {
			cin>>u;
			cnt = 0;
			for (int i=1; i<=n; i++)
				seen[i] = 0;

			for (int v: adj[u])
				dfs(v);

			cout << n-cnt;
			for (int i=1; i<=n; i++)
				if (!seen[i])
					printf(" %d", i);
			putchar('\n');
		}
	}
}
