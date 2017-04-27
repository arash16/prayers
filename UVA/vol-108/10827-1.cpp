#include <bits/stdc++.h>
#define INF 2147483647
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

// -------------------------------------------------------------

int X[155][155], C[155], n;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T = readInt();
	while (T--) {
		n = readInt();
		int bs = -INF;
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				bs = max(bs, X[i][j] = readInt());

		if (bs > 0)
			for (int i1=0; i1<n; ++i1) {
				memset(C, 0, n*sizeof(int));
				for (int i2=0; i2<n; ++i2) {
					int tsum = 0;
					for (int j=0; j<n; ++j)
						tsum += (C[j] += X[(i1+i2)%n][j]);

					int s1=0, s2=0;
					for (int j=0; j<n; ++j) {
						if ( (s1 += C[j]) < 0 )
							s1 = 0;

						if ( (s2 -= C[j]) < 0 )
							s2 = 0;

						bs = max(bs, max(s1, tsum+s2));
					}
				}
			}

		cout << bs << endl;
	}
}
