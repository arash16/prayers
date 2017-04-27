#include <stdio.h>
#include <iostream>
#include <queue>
#include <list>
using namespace std;

int ids[1000];
int find(int u) {
	return ids[u]==u ? u : ids[u] = find(ids[u]);
}
void join(int u, int v) {
	ids[find(u)] = find(v);
}

struct Edge {
	int u, v, w;
	Edge(int u, int v, int w):u(u),v(v),w(w){}
	bool operator < (const Edge &e) const {
		return w > e.w;
	}
};

bool seen[101];
int dist[101][101];
list<int> adj[101];
int maxLen(int u, int t) {
	seen[u] = 1;
	for (int v: adj[u])
		if (v == t) {
			seen[u] = 0;
			return dist[u][v];
		}
		else if (!seen[v]) {
			int r = maxLen(v, t);
			if (r >= 0) {
				seen[u] = 0;
				return max(r, dist[u][v]);
			}
		}
	seen[u] = 0;
	return -1;
}


int main(){
	int T, n, m, u, v, w;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; i++) {
			adj[i].clear();
			ids[i] = i;
		}

		priority_queue<Edge> q;
		for (int i=0; i<m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			u--; v--;
			q.push(Edge(u, v, w));
		}
		
		int s1 = 0;
		queue<Edge> q2;
		for (int cnt=0; cnt<n-1; ) {
			Edge e = q.top(); q.pop();
			if (find(e.u) != find(e.v)) {
				dist[e.u][e.v] = dist[e.v][e.u] = e.w;
				adj[e.u].push_back(e.v);
				adj[e.v].push_back(e.u);
				join(e.u, e.v);
				s1 += e.w;
				cnt++;
			}
			else q2.push(e);
		}
		for (; !q.empty(); q.pop()) 
			q2.push(q.top());

		int s2 = 1000000;
		while (!q2.empty()) {
			Edge e = q2.front(); q2.pop();
			if (!seen[e.u] || !seen[e.v]) {
				int mlen = maxLen(e.u, e.v);
				if (mlen >= 0 && mlen <= e.w)
					s2 = min(s2, s1 + e.w - mlen);
			}
		}
		printf("%d %d\n", s1, s2);
	}
}
