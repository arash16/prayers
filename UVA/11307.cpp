#include <bits/stdc++.h>
#define INF 268435456
using namespace std;

inline int readchar(bool flag = true) {
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
    int result = *p;
    if (flag) p++;
    return result;
}

inline bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline int readUInt() {
	char ch;
	unsigned int r=0;
	while (!isdigit(ch=readchar()))
		if (ch == EOF) return EOF;
	r = ch-'0';

	while (isdigit(ch=readchar(0)))
		r = (r<<3) + (r<<1) + (ch=readchar())-'0';

	return r;
}

// -----------------------------------------------------------------

vector<int> adj[10043];
int DP[10043][17], n;
bool inside[10043];
void dfs(int u) {
	inside[u] = 1;

	for (int v: adj[u])
		if (!inside[v])
			dfs(v);

	for (int i=1; i<11; ++i) {
		DP[u][i] = i;
		for (int v: adj[u])
			if (!inside[v]) {
				int mn = INF;
				for (int j=1; j<11; ++j) 
					if (i!=j && DP[v][j]<mn)
						mn = DP[v][j];

				DP[u][i] += mn;
			}
	}

	inside[u] = 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	while ((n=readUInt()) > 0) {
		for (int i=0; i<n; ++i)
			adj[i].clear();

		for (int i=0; i<n; ++i) {
			int u = readUInt();readchar();
			while (readchar(0)!='\n') {
				int v = readUInt();
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}

		dfs(0);
		int mn = INF;
		for (int i=1; i<11; ++i)
			mn = min(mn, DP[0][i]);
		cout << mn << endl;
	}
}
