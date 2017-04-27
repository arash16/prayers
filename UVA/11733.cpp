#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

inline int readchar() {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    static bool fin = 0;
    if (fin) return EOF;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf) {
        	fin = 1;
        	return EOF;
    	}
        p = buf;
    }
    return *p++;
}

bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline int readInt() {
	char ch;
	int sgn=1, r=0;
	while (!isdigit(ch=readchar()) && ch!='-')
		if (ch == EOF)
			return EOF;
	if (ch == '-') sgn = -1;
	else r = ch-'0';
	while (isdigit(ch=readchar()))
		r = (r<<3) + (r<<1) + ch-'0';
	return sgn*r;
}

// -----------------------------------------------------------------

#define MAXN 10017
int par[MAXN];
int find(int u) { return par[u]<0 ? u : par[u]=find(par[u]); }
void join(int u, int v) {
	if ((u=find(u)) == (v=find(v))) return;
	if (par[v] < par[u])
		swap(u, v);
	par[u] += par[v];
	par[v] = u;
}

// --------

struct Pair { 
	int u, v;
	Pair(){}
	Pair(int u, int v):u(u),v(v){}
};
vector<Pair> adj[MAXN];
int mindeg, maxdeg;
void qPush(int u, int v, int c) {
	while (c < mindeg)
		adj[--mindeg].clear();
	adj[c].push_back(Pair(u, v));
}

inline bool qEmpty() { return mindeg == maxdeg; }
int qPop(int &u, int &v) {
	int c = mindeg;
	Pair &p = adj[c].back();
	u = p.u; v = p.v;

	adj[c].pop_back();
	while (!qEmpty() && adj[mindeg].empty())
		++mindeg;

	return c;
}

// --------

int main() {
	for (int i=0; i<MAXN; ++i)
		adj[i].reserve(128);

	int T = readInt();
	for (int cse=1; cse<=T; ++cse) {
		int n = readInt(),
			m = readInt(),
			a = readInt();
		
		// a should be <10000 but is bigger
		maxdeg = mindeg = min(a, MAXN);

		memset(par, -1, (n+1)*sizeof(int));
		for (int i=0; i<m; ++i) {
			int u = readInt(),
				v = readInt(),
				c = readInt();

			if (c < maxdeg) qPush(u, v, c);
		}

		int sum = 0, cnt = 0;
		while (cnt < n-1 && !qEmpty()) {
			int u, v, c = qPop(u, v);
			if (find(u) != find(v)) {
				join(u, v);
				sum += c;
				++cnt;
			}
		}

		sum += (n-cnt) * a;
		printf("Case #%d: %d %d\n", cse, sum, n-cnt);
	}
}
