#include <bits/stdc++.h>
using namespace std;

#define INF 1073741824

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

// -----------------------------------------------------------
char D[10017], ID[10017];
unsigned int UID[117], M[117][117];
int main() {
	vector<int> X[101];
	for (int i=0; i<101; ++i)
		X[i].reserve(1000);

	int T = readUInt();
	while (T--) {
		int n = readUInt(),
			r = readUInt();

		int m = 0;
		memset(D, 0, n+1);
		for (int i=0; i<r; ++i) {
			X[i].clear();
			for (int j; (j=readUInt()); ) {
				X[i].push_back(j);
				if (++D[j] == 2)
					UID[ID[j] = m++] = j;
			}
		}

		for (int i=0; i<m; ++i) {
			for (int j=0; j<m; ++j)
				M[i][j] = INF;
			M[i][i] = 0;
		}

		for (int i=0; i<r; ++i) {
			int l=-1, u;
			for (int k=0; k<X[i].size(); ++k) {
				int j = X[i][k];
				if (D[j] > 1) {
					int v = ID[j];
					if (l!=-1 && k-l<M[u][v])
						M[u][v] =
						M[v][u] = k-l;

					l = k;
					u = v;
				}
			}
		}

		for (int k=0; k<m; ++k)
			for (int i=0; i<m; ++i)
				if (i != k && M[i][k]!=INF)
				for (int j=0; j<m; ++j)
					if (j != k)
					M[i][j] = min(M[i][j], M[i][k]+M[k][j]);

		int mins = 1<<30, mi;
		for (int i=0; i<m; ++i) {
			int sum = 0;
			for (int j=0; j<m; ++j)
				sum += M[i][j];
			
			if (sum < mins || (sum==mins && UID[i]<mi)) {
				mins = sum;
				mi = UID[i];
			}
		}
		printf("Krochanska is in: %d\n", mi);
	}
}
