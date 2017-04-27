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

// -------------------------------------------------------------------
#define INF 2147483647

struct UD {
	int u, d;
	UD(int u, int d):u(u),d(d){}
	bool operator < (const UD& ud) const { return d > ud.d; }
};

vector<UD> adj[20017];
int D[20017];


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T = readUInt();
	for (int cse=1; cse<=T; ++cse) {
		cout << "Case #" << cse << ": ";

		int n = readUInt(),
			m = readUInt(),
			src = readUInt(),
			dst = readUInt();

		for (int i=0; i<n; ++i) {
			adj[i].clear();
			D[i] = INF;
		}

		for (int i=0; i<m; ++i) {
			int u = readUInt(),
				v = readUInt(),
				w = readUInt();

			adj[u].push_back(UD(v, w));
			adj[v].push_back(UD(u, w));
		}

		priority_queue<UD> q;
		q.push(UD(src, D[src]=0));
		while (!q.empty()) {
			UD ud = q.top(); q.pop();
			int u = ud.u;
			if (D[u] != ud.d) continue;
			if (u == dst) {
				cout << ud.d << endl;
				goto fin;
			}

			for (UD vd: adj[u]) {
				UD t(vd.u, ud.d+vd.d);
				if (t.d < D[vd.u]) {
					D[t.u] = t.d;
					q.push(t);
				}
			}
		}
		cout << "unreachable\n";
		fin:;
	}
}
