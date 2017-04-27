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

bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline unsigned int readUInt() {
	char ch;
	unsigned int r=0;
	while (!isdigit(ch=readchar()));
	r = ch-'0';
	while (isdigit(ch=readchar()))
		r = (r<<3) + (r<<1) + ch-'0';
	while (ch!='\n') ch=readchar();
	return r;
}

int readLine(char *str) {
	int len=0;
	char ch;
	while ((ch=readchar())!='\n' && ch!=EOF)
		str[len++] = ch;
	
	if (ch == EOF && !len) return EOF;
	str[len] = 0;
	return len;
}

// ------------------------------------------------------------

char M[320][880];
bool S[320][880];
int ll[320], h, w,
	dy[] = {0,1,0,-1},
	dx[] = {1,0,-1,0};
void dfs(int y, int x) {
	if (S[y][x]) return;
		S[y][x] = 1;
	if (x < ll[y]) 
		M[y][x] = ' ';

	for (int k=0; k<4; ++k) {
		int ny=y+dy[k], nx=x+dx[k];
		if (ny>=0 && ny<h && nx>=0 && nx<w) {
			if (nx<ll[ny] && M[ny][nx] != ' ' && M[ny][nx]!='#') {
				M[y][x] = '#';
				if (ll[y] <= x) {
					for (int i=ll[y]; i<x; ++i)
						M[y][i] = ' ';
					M[y][ll[y]=x+1] = 0;
				}
			}
			else dfs(ny, nx);
		}
	}
}

int main() {
	int T = readUInt();
	while (T--) {
		w = 0;
		for (h=0; (ll[h]=readLine(M[h]))!=EOF && M[h][0]!='_'; ++h)
			w = max(w, ll[h]+1);

		for (int i=0; i<h; ++i)
			memset(S[i], 0, w);

		for (int i=0; i<h; ++i)
			for (int j=0; M[i][j]; ++j)
				if (M[i][j] == '*') {
					dfs(i, j);
					goto fin;
				}
		fin:
		for (int i=0; i<=h; ++i) {
			while (M[i][ll[i]-1]==' ')
				--ll[i];
			M[i][ll[i]] = 0;
			puts(M[i]);
		}
	}
}
