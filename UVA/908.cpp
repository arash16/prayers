#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

#define MAXN 1000017
unordered_map<int, int> M[MAXN];
list<int> adj[MAXN];
int parent[MAXN], depth[MAXN];
void reparent(int u, int d) {
	depth[u] = d;
	for (int v: adj[u])
		if (v != parent[u]) {
			parent[v] = u;
			reparent(v, d+1);
		}
}

int reconnect(int u, int v, int w) {
	int a=u, b=v, tw,
		bw=w, bd, bi, bj;

	while (a != b) {
		if (depth[a] >= depth[b]) {
			tw = M[a][parent[a]];
			if (tw > bw) {
				bd = 1;
				bw = tw;
				bi = a;
				bj = parent[a];
			}
			a = parent[a];
		}
		
		if (depth[b] > depth[a]) {
			tw = M[b][parent[b]];
			if (tw > bw) {
				bd = 2;
				bw = tw;
				bi = b;
				bj = parent[b];
			}
			b = parent[b];
		}
	}
	
	if (bw > w) {
		adj[bi].remove(bj);
		adj[bj].remove(bi);
		adj[u].push_back(v);
		adj[v].push_back(u);
		M[u][v] = M[v][u] = w;
		if (bd == 1) {
			parent[u] = v;
			reparent(u, depth[v]+1);
		}
		else {
			parent[v] = u;
			reparent(v, depth[u]+1);
		}
		
		return bw-w;
	}
	return 0;
}

int main(){
	bool frst = 1;
	int n, m, k, u, v, w;
	while (scanf("%d", &n)==1) {
		if (frst) frst = 0;
		else putchar('\n');

		for (int i=1; i<=n; i++) {
			adj[i].clear();
			M[i].clear();
		}

		long long sum = 0;
		for (int i=1; i<n; i++) {
			scanf("%d%d%d", &u, &v, &w);
			M[u][v] = M[v][u] = w;
			adj[u].push_back(v);
			adj[v].push_back(u);
			sum += w;
		}
		printf("%lld\n", sum);
		reparent(1, 0);

		scanf("%d", &k);
		for (int i=0; i<k; i++) {
			scanf("%d%d%d", &u, &v, &w);
			sum -= reconnect(u, v, w);
		}
		printf("%lld\n", sum);

		scanf("%d", &m);
		for (int i=0; i<m; i++)
			scanf("%*d %*d %*d");
	}
}
