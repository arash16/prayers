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

// --------------------------------------------------------------------------------------

int Y[1000043], MX[1000043], MN[1000043], mxn;
int assignRange(int rl, int rr, int val, int rest=-1, int sl=0, int sr=mxn, int si=1) {
	if (val < MN[si]) return 0;
	if (rl<=sl && rr>=sr && val >= MX[si]) 
		Y[si] = MX[si] = MN[si] = val;
	if (Y[si] == val) 
		return max(min(rr, sr)-max(rl, sl), 0);

	if (rest == -1) rest = Y[si];
	if (rl>=sr || rr<=sl) {
		if (rest != -1)
			Y[si] = MX[si] = MN[si] = rest;
		return 0;
	}

	int id1 = si<<1, id2 = si<<1|1;
	if (Y[si] != -1)
		Y[id1] = Y[id2] =
		MX[id1] = MX[id2] =
		MN[id1] = MN[id2] = Y[si];

	int mid = (sl + sr) >> 1;
	int result = 
		assignRange(rl, rr, val, rest, sl, mid, id1) +
		assignRange(rl, rr, val, rest, mid, sr, id2);
	
	if (Y[id1] == Y[id2] && Y[id1]!=-1)
		Y[si] = MX[si] = MN[si] = Y[id1];

	else {
		Y[si] = -1;
		MX[si] = max(MX[id1], MX[id2]);
		MN[si] = min(MN[id1], MN[id2]);
	}
	return result;
}

int getPoint(int ind, int sl=0, int sr=mxn, int si=1) {
	if (Y[si]>=0) return Y[si];
	int mid = (sl + sr) >> 1;
	return ind < mid
		? getPoint(ind, sl, mid, si<<1)
		: getPoint(ind, mid, sr, si<<1|1);
}



int L[100043], R[100043], H[100043];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T = readUInt();
	while (T--) {
		int n = readUInt();
		int sum = mxn = Y[1] = MX[1] = MN[1] = 0;
		for (int i=0; i<n; ++i) {
			L[i] = readUInt();
			R[i] = readUInt();
			H[i] = readUInt();
			mxn = max(mxn, R[i]);
		}

		for (int i=0; i<n; ++i)
			sum += assignRange(L[i], R[i], H[i]);

		cout << sum << "\n";
	}
}
