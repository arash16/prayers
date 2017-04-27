#include <bits/stdc++.h>
using namespace std;

inline int readchar() {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    bool fin = 0;
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

inline bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline int readUInt() {
	char ch;
	unsigned int r=0;
	while (!isdigit(ch=readchar()))
		if (ch == EOF) return EOF;
	r = ch-'0';
	while (isdigit(ch=readchar()))
		r = (r<<3) + (r<<1) + ch-'0';

	while (ch!=' ' && ch!='\n')
		ch = readchar();
	return r;
}

// -----------------------------------------------------------------------------

struct Island {
	int x, y, r;
	bool operator < (const Island &o) const { return x-r < o.x-o.r; }
	bool operator ==(const Island &o) const { return x==o.x && y==o.y && r==o.r; }
} P[143], srcI, dstI;


void readIsland(Island &I) {
	I.x = readUInt();
	I.y = readUInt();
	I.r = readUInt();
}

vector<int> adj[143];
int src, dst, seen[143];
bool dfs(int u) {
	for (int v: adj[u])
		if (!seen[v]) {
			 seen[v] = 1;
			if (v == dst || dfs(v)) 
				return 1;
		}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);

	int k;
	while ((k=readUInt())!=EOF) {
		int t = readUInt();
		int maxd = k * t,
			mxd2 = maxd*maxd;

		readIsland(srcI); P[0] = srcI;
		readIsland(dstI); P[1] = dstI;
		int n = readUInt();
		for (int i=0; i<n; ++i)
			readIsland(P[i+2]);
		sort(P, P+(n+=2));

		for (int i=0; i<n; ++i) {
			if		(P[i] == srcI) src = i;
			else if	(P[i] == dstI) dst = i;
			adj[i].clear();
			seen[i] = 0;
		}

		for (int i=0; i<n; ++i) {
			int rr = P[i].x + P[i].r;
			for (int j=i+1; j<n && P[j].x-P[j].r-rr <= maxd; ++j) {
				int xx = P[i].x - P[j].x,
					yy = P[i].y - P[j].y;
				double d = sqrt(double(xx*xx + yy*yy)) - P[i].r - P[j].r;
				if (d <= maxd) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		cout << (dfs(src) ? "Larry and Ryan will escape!\n" : "Larry and Ryan will be eaten to death.\n");
	}
}
