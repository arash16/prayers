#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

#define MAXN 1001
list<int> adj[MAXN];
int low[MAXN], depth[MAXN], parent[MAXN];

void print(int u, int v) {
	printf("%d %d\n", u+1, v+1);
}

void dfs(int u, int d) {
	low[u] = depth[u] = d;
	for (int v: adj[u])
		if (depth[v] == -1) {
			print(u, v);
			parent[v] = u;
			dfs(v, d+1);
			if (low[v] >= d+1)
				print(v, u);
			else if (low[v] < low[u])
				low[u] = low[v];
		}
		else if (v != parent[u]) {
			low[u] = min(low[u], depth[v]);
			if (depth[v] < depth[u])
				print(u, v);
		}
}


int main(){
	int cse=1, n, m, u, v;
	while (cin>>n>>m && (n||m)) {
		for (int i=0; i<n; i++) {
			adj[i].clear();
			depth[i]=-1;
		}

		for (int i=0; i<m; i++) {
			cin>>u>>v;
			adj[u-1].push_back(v-1);
			adj[v-1].push_back(u-1);
		}
		
		printf("%d\n\n", cse++);
		dfs(0, 0);
		puts("#");
	}
}
