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

char buf[50];
void print(long long x) {
	int i=48, neg=0;
	buf[i--] = '\n';
	if (!x) buf[i--] = '0';
	else if (x < 0) {
		x = -x;
		neg = 1;
	}
	for (; x; x/=10)
		buf[i--] = x%10 + '0';

	if (neg) buf[i--] = '-';
	fwrite_unlocked(buf+i+1, 1, 48-i, stdout);
}

void printNl() {
	buf[0] = '\n';
	fwrite_unlocked(buf, 1, 1, stdout);
}

// ---------------------------------------------------------------------------

#define MAXQS 16384
class FastQueue {
	int data[MAXQS], l, r;
	public:
		FastQueue():l(0),r(0) {}
		void clear() { l=r=0; }
		bool empty() { return l==r; }
		void push(int x) { data[r++] = x; r&=MAXQS-1; }
		int pop() { int result = data[l++]; l&=MAXQS-1; return result; }
		int front() { return data[l]; }
		int size() { return r>=l ? r-l : MAXQS-l+r; }
};

int C[MAXQS];
vector<int> adj[MAXQS];
int main() {
	FastQueue q;

	int n, m;
	bool frst = 1;
	while ((n=readUInt())!=EOF) {
		if (frst) frst = 0;
		else printNl();

		for (int i=0; i<n; ++i)
			adj[i].clear();

		m = readUInt();
		for (int i=0; i<m; ++i) {
			int u = readUInt()-1,
				v = readUInt()-1;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int k=0, sr;
		for (int i=0; i<n; ++i) {
			C[i] = -1;
			int sz = adj[i].size();
			if (sz > k) {
				k = sz;
				sr = i;
			}
		}
		k |= 1;

		C[sr]=0;
		q.clear();
		q.push(sr);
		while (!q.empty()) {
			int u = q.pop(),
				nc = (C[u]+1) % k;
			for (int v: adj[u])
				if (C[v]<0) {
					C[v] = nc;
					q.push(v);
				}
				else if (C[v] == C[u])
					C[v] = nc;
		}

		print(k);
		for (int i=0; i<n; ++i)
			print(C[i]+1);
	}
}
