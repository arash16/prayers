#include <stdio.h>
#include <iostream>
#include <map>
#include <list>
using namespace std;


struct Road {
	int id, v;
	Road(int id, int v):id(id),v(v) {}
};

list<Road> adj[200001];
int cse, cidv[200001], prot[200001];
void checkId(int u) {
	if (cidv[u] != cse) {
		cidv[u] = cse;
		adj[u].clear();
	}
}

int best;
bool inside[200001];
int dfs(int u) {
	inside[u]=1;

	int sum = 0;
	for (Road r: adj[u]) if (!inside[r.v]) {
		int pr = prot[r.id] + dfs(r.v);
		if (pr > 0) sum += pr;
	}
	if (sum > best) 
		best = sum;

	inside[u]=0;
	return sum;
}


int main() {
	int n, u, v;
	while (scanf("%d", &n)==1 && n) {
		cse++;
		for (int i=0; i<n; i++) {
			scanf("%d%d%d", &u, &v, prot+i);
			checkId(u); checkId(v);
			adj[u].push_back(Road(i, v));
			adj[v].push_back(Road(i, u));
		}
		
		best = 0; dfs(u);
		printf("%d\n", best);
	}
}
