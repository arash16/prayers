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

#define MAXN 100001

struct Point {
	int x, y;
};

vector<Point> a, b;
int dist(int i, int j) {
	return abs(a[i].x-b[j].x) + abs(a[i].y-b[j].y);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	for (int cse=1, n; (n=readUInt()); ++cse) {
		a.resize(n);
		for (int i=0; i<n; ++i) {
			a[i].x = readUInt();
			a[i].y = readUInt();
		}
		
		int m = readUInt();
		b.resize(m);
		for (int i=0; i<m; ++i) {
			b[i].x = readUInt();
			b[i].y = readUInt();
		}
		
		int res = 500000000;
		if (n*m < MAXN)
			for (int i=0; i<n; ++i)
				for (int j=0; j<m; ++j)
					res = min(res, dist(i, j));
		else
			for (int i=0; i<MAXN; ++i)
				res = min(res, dist(rand()%n, rand()%m));

		cout << res << endl;
	}
}
