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

// ------------------------------------------------------------------------

inline int sgn(int x) { return x < 0 ? -1 : x > 0 ? 1 : 0; }

struct State {
	int i, j, d;
	State(int i, int j, int d):i(i),j(j),d(d){}
};

int B[2017][2017], S[2017][2017],
	dx[] = {0,0,1,-1},
	dy[] = {1,-1,0,0};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	for (int cse=1, n; (n=readUInt()); ++cse) {
		int mnx=3000, mny=3000, mxx=0, mxy=0;

		int cx, cy;
		for (int i=0; i<n; ++i) {
			int x = readUInt(),
				y = readUInt();
			mnx = min(mnx, x);
			mny = min(mny, y);
			mxx = max(mxx, x);
			mxy = max(mxy, y);
			if (!i) {
				cx = x; 
				cy = y;
			}
			else {
				int dx = sgn(x-cx), dy = sgn(y-cy);
				for (; cx != x || cy != y; cx += dx, cy += dy)
					B[cy][cx] = cse;
			}
		}
		B[cy][cx] = cse;


		queue<State> q;
		int m = readUInt();
		for (int i=0; i<m; ++i) {
			int x = readUInt(),
				y = readUInt();
			mnx = min(mnx, x);
			mny = min(mny, y);
			mxx = max(mxx, x);
			mxy = max(mxy, y);
			if (!i) {
				cx = x; 
				cy = y;
			}
			else {
				int dx = sgn(x-cx), dy = sgn(y-cy);
				for (; cx != x || cy != y; cx += dx, cy += dy) {
					S[cy][cx] = cse;
					q.push(State(cy, cx, 0));
				}
			}
		}


		while (!q.empty()) {
			State s=q.front(); q.pop();
			for (int k=0; k<4; ++k) {
				State t(s.i+dy[k], s.j+dx[k], s.d+1);
				if (t.i>=mny && t.i<=mxy && t.j>=mnx && t.j<=mxx && S[t.i][t.j]!=cse) {
					if (B[t.i][t.j]==cse) {
						cout << t.d << endl;
						goto fin;
					}
					S[t.i][t.j] = cse;
					q.push(t);
				}
			}
		}
		fin:;
	}
}
