#include <stdio.h>
#include <cstring>
#include <iostream>
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

char buf[50];
void print(long long x) {
	int i=48, neg=0;
	buf[i--] = '\n';
	if (!x) buf[i--] = '0';
	for (; x; x/=10)
		buf[i--] = x%10 + '0';

	fwrite_unlocked(buf+i+1, 1, 48-i, stdout);
}

// ---------------------------------------------------------------------------
#define MAXN 501
int C[MAXN], ids[10000], gid[MAXN];
int abs(int x) { return x<0 ? -x : x; }
int dist(int i, int j) {
	int x = C[i], y = C[j],
		d = 0;
	for (int k=0; k<4; ++k) {
		int t = abs(x%10 - y%10);
		d += min(t, 10-t);
		x /= 10;
		y /= 10;
	}
	return d;
}

int find(int u) { return u == gid[u] ? u : gid[u] = find(gid[u]); }
void join(int u, int v) { gid[find(u)] = find(v); }

// ----

int deg[40], mindeg;
struct Pair { int i, j; } adj[40][MAXN*MAXN];
void qPush(int i, int j) {
	int d = dist(i, j);
	adj[d][deg[d]].i = i;
	adj[d][deg[d]].j = j;
	++deg[d];
	if (d < mindeg) mindeg = d;
}

bool qEmpty() { return mindeg==40; }

int qPop(int &u, int &v) {
	int d = mindeg;
	Pair &p = adj[d][--deg[d]];
	while (mindeg<40 && !deg[mindeg]) ++mindeg;

	u = p.i; 
	v = p.j;
	return d;
}

// ----

int main() {
	int T = readUInt();
	while (T--) {
		mindeg = 40;
		memset(deg, 0, sizeof(deg));

		int n = readUInt();
		for (int i=0; i<n; ++i) {
			C[i] = readUInt();
			ids[C[i]] = i;
			gid[i] = i;

			for (int j=0; j<i; ++j)
				qPush(j, i);
		}
		C[ids[0]=n] = 0;
		int sum = 100;
		for (int j=0; j<n; ++j)
			sum = min(sum, dist(j, n));

		for (int cnt=1; cnt<n; ) {
			int u, v, d = qPop(u, v);
			if (find(u) != find(v)) {
				join(u, v);
				sum += d;
				++cnt;
			}
		}

		print(sum);
	}
}
