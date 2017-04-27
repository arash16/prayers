#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int ids[1001];
int find(int u) {
	return u==ids[u] ? u : ids[u] = find(ids[u]);
}
void join(int u, int v) {
	ids[find(u)] = find(v);
}

struct Edge {
	int u, v, w;

	Edge (int u, int v, int w) : u(u), v(v), w(w){}
	bool operator < (const Edge &e) const { return w > e.w; }
};

int main(){
	int n, m, u, v, w;
	while (scanf("%d%d", &n, &m)==2 && (n||m)) {
		for (int i=0; i<n; i++)
			ids[i] = i;

		priority_queue<Edge> q;
		for (int i=0; i<m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			q.push(Edge(u, v, w));
		}
		
		int frst = 1;
		while (!q.empty()) {
			Edge e = q.top(); q.pop();
			if (find(e.u) != find(e.v)) 
				join(e.u, e.v);
			else {
				if (frst) frst = 0;
				else putchar(' ');
				printf("%d", e.w);
			}
		}
		if (frst) puts("forest");
		else putchar('\n');
	}
}
