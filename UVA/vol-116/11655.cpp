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

// ----------------------------------------------------------------------

#define MODUL 100000
int C1[5555], C2[5555], n;
vector<int> adj[5555], adjr[5555];
bool seen[5555], isin[5555];
int ord[5555], oi;
void dfs(int u) {
	seen[u] = true;

	if (!(isin[u] = u==n-1))
		for (int v: adj[u]) {
			if (!seen[v])
				dfs(v);
			isin[u] |= isin[v];
		}

	if (isin[u])
		ord[--oi] = u;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T = readUInt();
	for (int cse=1; cse<=T; ++cse) {
		n = readUInt();
		for (int i=0; i<n; ++i)
			adj[i].clear(),
			adjr[i].clear();

		int m = readUInt();
		while (m--) {
			int u = readUInt()-1,
				v = readUInt()-1;
			adj[u].push_back(v);
			adjr[v].push_back(u);
		}
		
		memset(seen, 0, oi=n);
		dfs(0);
		
		memset(C1, 0, n*sizeof(int));
		memset(C2, 0, n*sizeof(int));
		C1[0] = C2[n-1] = 1;

		for (int i=oi; i<n; ++i) {
			int u = ord[i];
			for (int v: adj[u])
				C1[v] = (C1[v] + C1[u]) % MODUL;
		}

		int s = 0;
		for (int i=n-1; i>=oi; --i) {
			int u = ord[i];
			if (u)
			s = (s + (long long)C1[u] * C2[u]) % MODUL;
			for (int v: adjr[u])
				C2[v] = (C2[v] + C2[u]) % MODUL;
		}

		cout << "Case " << cse << ": "
			<< s << ' ' << C1[n-1] << "\n";
	}
}
