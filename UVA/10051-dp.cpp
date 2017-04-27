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

// --------------------------------------------------------------------

char fnames[6][10] = {
	"front", "back", 
	"left", "right", 
	"top", "bottom"
};

int C[555][6], D[555][6], n;
struct State {
	int i, j;
	State():i(0),j(0){}
	State(int i, int j):i(i),j(j){}
} P[555][6];


char BUF[1000000];
int main() {
	cout.rdbuf()->pubsetbuf(BUF, 1000000);
	ios_base::sync_with_stdio(0);cin.tie(0);

	for (int cse=1; (n=readUInt()); ++cse) {
		for (int i=0; i<n; ++i)
			for (int j=0; j<6; ++j)
				C[i][j] = readUInt();

		int bestd=0;
		State best;
		for (int i=n-1; i>=0; --i)
			for (int c=0; c<6; ++c) {
				int bc = C[i][c^1];

				D[i][c] = 1;
				for (int j=i+1; j<n; ++j)
					for (int k=0; k<6; ++k)
						if (C[j][k] == bc && D[j][k]+1>D[i][c])
							D[i][c] = D[j][k]+1,
							P[i][c] = State(j, k);

				if (D[i][c] > bestd) {
					bestd = D[i][c];
					best = State(i, c);
				}
			}

		if (cse > 1) cout << "\n";
		cout << "Case #" << cse << "\n" << bestd << "\n";
		for (int i=0; i<bestd; ++i) {
			cout << best.i+1 << ' ' << fnames[best.j] << "\n";
			best = P[best.i][best.j];
		}
	}
}
