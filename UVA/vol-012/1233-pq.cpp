#include <bits/stdc++.h>
#define INF 1073741824
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

// ----------------------------------------------------------------------

struct State {
	int u, d;
	State(int u, int d):u(u),d(d){}
	bool operator < (const State &o) const { return d > o.d; }
};

vector<int> adj[555];
int D[555], W[555][555], S[555][555];

int main() {
	ios_base::sync_with_stdio(0);

	int T = readUInt();
	for (int cse=1; cse<=T; ++cse) {
		int c = readUInt(),
			n = readUInt() + 1,
			m = readUInt();

		priority_queue<State> q;
		for (int i=0; i<n; ++i) D[i] = INF;
		for (int i=0; i<m; ++i) {
			int u = readUInt();
			q.push(State(u, D[u]=0));
		}

		for (int u=1; u<n; ++u) {
			m = readUInt();
			adj[u].clear();
			while (m--) {
				int d = readUInt(),
					v = readUInt();
				if (S[u][v]!= cse) {
					S[u][v] = cse;
					W[u][v] = d;
					adj[u].push_back(v);
				}
				else W[u][v] = min(W[u][v], d);
			}
		}


		while (!q.empty()) {
			State s = q.top(); q.pop();
			if (s.d != D[s.u]) continue;
			if (s.u == 0) {
				cout << (c-2) / (s.d-1) << endl;
				goto fin;
			}

			for (int v: adj[s.u]) {
				int d = s.d + W[s.u][v];
				if (d < D[v] && d < c)
					q.push(State(v, D[v]=d));
			}
		}
		cout << "0\n";
		fin:;
	}
}
