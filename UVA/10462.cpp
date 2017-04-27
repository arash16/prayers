#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <list>
using namespace std;

#define INF 1073741824
typedef unsigned char byte;
char NOWAY[] = "No way",
	 NO2WAY[] = "No second way";
byte gid[117];

byte find(byte u) { return gid[u]==u ? u : gid[u]=find(gid[u]); }
void join(byte u, byte v) { gid[find(u)] = find(v); }

struct Edge {
	int w;
	byte u, v;
	Edge(byte u, byte v, int w):u(u),v(v),w(w) {}
	bool operator < (const Edge &e) const { return w > e.w; }
};

int d[117][117], depth[117], parent[117];
list<byte> adj[117];
void reparent(int u, int de) {
	depth[u] = de;
	byte mypar = parent[u];
	for (byte v: adj[u])
		if (v != mypar) {
			parent[v] = u;
			reparent(v, de+1);
		}
}

int maxlen(int u, int v) {
	int mx = 0;
	while (u != v) {
		if (depth[u] >= depth[v]) {
			mx = max(mx, d[u][parent[u]]);
			u = parent[u];
		}

		if (depth[v] > depth[u]) {
			mx = max(mx, d[v][parent[v]]);
			v = parent[v];
		}
	}
	return mx;
}

int main(){
	srand(rand()-1);
	int T, n, m, u, v, w;

	scanf("%d", &T);
	for (int cse=1; cse<=T; ++cse) {
		printf("Case #%d : ", cse);
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; i++) {
			adj[i].clear();
			gid[i] = i;
		}

		queue<Edge> q2;
		priority_queue<Edge> q;
		for (int i=0; i<m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			q.push(Edge(u-1, v-1, w));
		}

		if (m < n-1) puts(NOWAY);
		else {
			int c=0, sum=0;
			while (c<n-1 && !q.empty()) {
				Edge e = q.top(); q.pop();
				if (find(e.u) != find(e.v)) {
					++c;
					sum += e.w;
					join(e.u, e.v);
					adj[e.u].push_back(e.v);
					adj[e.v].push_back(e.u);
					d[e.u][e.v]=d[e.v][e.u] = e.w;
				}
				else q2.push(e);
			}

			if (c < n-1) puts(NOWAY);
			else if (m == n-1) puts(NO2WAY);

			else {
				for (;!q.empty(); q.pop())
					q2.push(q.top());


				byte root = rand()%n;
				parent[root] = root;
				reparent(root, 0);



				int diff = INF;
				while (diff && !q2.empty()) {
					Edge e = q2.front(); q2.pop();
					diff = min(diff, e.w - maxlen(e.u, e.v));
				}



				printf("%d\n", sum + diff);
			}
		}
	}
}
