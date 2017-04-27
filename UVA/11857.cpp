#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

inline int readchar() {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf) 
        	return EOF;
        p = buf;
    }
    return *p++;
}

bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline unsigned int readUInt() {
	char ch;
	unsigned int r=0;
	while (!isdigit(ch=readchar()));
	r = ch-'0';
	while (isdigit(ch=readchar()))
		r = (r<<3) + (r<<1) + ch-'0';
	return r;
}

// ------------------------------------------------------------

#define MAXN 1000017
int par[MAXN];
int find(int u) { return par[u]<0 ? u : par[u]=find(par[u]); }
void join(int u, int v) {
	if ((u=find(u)) == (v=find(v))) return;
	if (par[v] < par[u])
		swap(u, v);
	par[u] += par[v];
	par[v] = u;
}


struct Edge {
	int u, v, d;
	bool operator < (const Edge &e) const { return d < e.d; }
} q[MAXN];


int main() {
	int n;
	while ((n=readUInt())) {
		memset(par, -1, n*sizeof(int));

		int m=readUInt();
		for (int i=0; i<m; ++i) {
			q[i].u = readUInt();
			q[i].v = readUInt();
			q[i].d = readUInt();
		}

		sort(q, q+m);
		int cnt=1, mxd=0;
		for (int i=0; cnt < n && i<m; ++i) {
			int u = q[i].u, v = q[i].v, d = q[i].d;
			if (find(u) != find(v)) {
				join(u, v);
				mxd = d;
				++cnt;
			}
		}

		if (cnt < n) puts("IMPOSSIBLE");
		else printf("%d\n", mxd);
	}
}
