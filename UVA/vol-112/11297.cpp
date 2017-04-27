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
inline char readcm() {
	char ch;
	while ( (ch=readchar())==' ' || ch=='\n' || ch=='\t' );
	return ch;
}

// ------------------------------------------------------------------

inline int max(int a, int b, int c, int d) {
	return	a>b && a>c && a>d ? a :
			b>c && b>d ? b :
			c>d ? c :
			d;
}
inline int min(int a, int b, int c, int d) {
	return	a<b && a<c && a<d ? a :
			b<c && b<d ? b :
			c<d ? c :
			d;
}
inline int chid(int id, int j) {
	return (id << 2) | j;
}

int V[555][555], MN[1000143], MX[1000143], n;
void initialize(int x1=0, int y1=0, int x2=n, int y2=n, int id=1) {
	if (x2-x1 <= 1 && y2-y1 <= 1) {
		if (x2-x1==1 && y2-y1==1)
			 MN[id] = MX[id] = V[x1][y1];
		else MX[id] = -(MN[id] = INF);
		return;
	}

	int mx = (x1 + x2) >> 1,
		my = (y1 + y2) >> 1,
		id1,id2,id3,id4;

	initialize(x1, y1, mx, my, id1=chid(id, 0));
	initialize(mx, y1, x2, my, id2=chid(id, 1));
	initialize(x1, my, mx, y2, id3=chid(id, 2));
	initialize(mx, my, x2, y2, id4=chid(id, 3));
	MN[id] = min( MN[id1] , MN[id2] , MN[id3] , MN[id4] );
	MX[id] = max( MX[id1] , MX[id2] , MX[id3] , MX[id4] );
}

void updateValue(int x, int y, int x1=0, int y1=0, int x2=n, int y2=n, int id=1) {
	if (x<x1 || x>=x2 || y<y1 || y>=y2) return;
	if (x2-x1==1 && y2-y1==1)
		MN[id] = MX[id] = V[x1][y1];
	if (x2-x1<=1 && y2-y1<=1) return;

	int mx = (x1 + x2) >> 1,
		my = (y1 + y2) >> 1,
		id1,id2,id3,id4;

	updateValue(x, y, x1, y1, mx, my, id1=chid(id, 0));
	updateValue(x, y, mx, y1, x2, my, id2=chid(id, 1));
	updateValue(x, y, x1, my, mx, y2, id3=chid(id, 2));
	updateValue(x, y, mx, my, x2, y2, id4=chid(id, 3));
	MN[id] = min( MN[id1] , MN[id2] , MN[id3] , MN[id4] );
	MX[id] = max( MX[id1] , MX[id2] , MX[id3] , MX[id4] );
}

int maxx, minn;
void solve(int qx1, int qy1, int qx2, int qy2, int x1=0, int y1=0, int x2=n, int y2=n, int id=1) {
	if (qx1>=x2 || qx2<=x1 || qy1>=y2 || qy2<=y1 || (MN[id]>=minn && MX[id]<=maxx))
		return;

	if (qx1<=x1 && qx2>=x2 && qy1<=y1 && qy2>=y2) {
		maxx = max(maxx, MX[id]);
		minn = min(minn, MN[id]);
		return;
	}

	int mx = (x1 + x2) >> 1,
		my = (y1 + y2) >> 1;
	solve(qx1, qy1, qx2, qy2, x1, y1, mx, my, chid(id, 0));
	solve(qx1, qy1, qx2, qy2, mx, y1, x2, my, chid(id, 1));
	solve(qx1, qy1, qx2, qy2, x1, my, mx, y2, chid(id, 2));
	solve(qx1, qy1, qx2, qy2, mx, my, x2, y2, chid(id, 3));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	n = readInt();
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			V[i][j] = readInt();

	initialize();
	int m = readInt();
	while (m--) {
		if (readcm() == 'c') {
			int x = readInt()-1,
				y = readInt()-1;
			V[x][y] = readInt();
			updateValue(x, y);
		}
		else {
			int x1 = readInt()-1,
				y1 = readInt()-1,
				x2 = readInt(),
				y2 = readInt();

			maxx = -INF;
			minn = +INF;
			solve(x1, y1, x2, y2);
			cout << maxx << ' ' << minn << "\n";
		}
	}
}
