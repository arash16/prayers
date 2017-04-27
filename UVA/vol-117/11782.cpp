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
inline int readInt() {
	char ch;
	int sgn=1, r=0;
	while (!isdigit(ch=readchar()) && ch!='-')
		if (ch == EOF) return EOF;
	if (ch == '-') sgn = -1;
	else r = ch-'0';
	while (isdigit(ch=readchar()))
		r = (r<<3) + (r<<1) + ch-'0';
	return sgn*r;
}

// ----------------------------------------------------------------

int DP[2100043][23], h, n;
int dfs(int id, int depth) {
	int val = readInt();
	if (depth < h)
		dfs(2*id+1, depth+1),
		dfs(2*id+2, depth+1);

	for (int i=1; i<=n; ++i) {
		DP[id][i] = val;
		if (depth < h)
			for (int j=1; j<i; ++j)
				DP[id][i] = max(DP[id][i], DP[2*id+1][j] + DP[2*id+2][i-j]);
	}
	return DP[id][n];
}

int main() {
	while ((h=readInt()) >= 0) {
		n = readInt();
		cout << dfs(0, 0) << endl;
	}
}
