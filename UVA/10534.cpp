#include <bits/stdc++.h>
using namespace std;

inline int readchar(bool skip=true) {
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
    if (skip) ++p;
    return result;
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

// --------------------------------------------------------------

int X[10043], Y[10043], M[10043], L[10043], R[10043], n;
int LIS(int X[], int R[]) {
	int L = 0;
	for (int i=0; i<n; ++i) {
		int lo = 1, hi = L;
		while (lo <= hi) {
			int mid = (lo + hi)>>1;
			if (M[mid] < X[i]) {
				lo = mid + 1;
				if (mid==L || M[lo]>=X[i]) break;
			}
			else hi = mid - 1;
		}

		R[i] = lo;
		M[lo] = X[i];
		L = max(L, lo);
	}
	return L;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	while ((n=readUInt()) != EOF) {
		for (int i=0; i<n; ++i)
			X[i] = Y[n-i-1] = readUInt();

		LIS(X, L);
		LIS(Y, R);

		int mx = 0;
		for (int i=0; i<n; ++i)
			mx = max(mx, 2*min(L[i], R[n-i-1])-1);
		cout << mx << "\n";
	}
}
