#include <bits/stdc++.h>
#define INF 1073741824
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

template<class T>
class IndexQueue {
	int mind, maxd;
	vector<T> V[600000];
	void _update() {
		while (mind<=maxd && V[mind].empty()) ++mind;
		if (mind>maxd) clear();
	}

	public:
	IndexQueue() { mind=INF; maxd=-1; }
	bool empty() { _update(); return mind>maxd; }
	void clear() {
		for (int i=mind; i<=maxd; ++i)
			V[i].clear();
		mind=INF; 
		maxd=-1;
	}

	void push(int key, T data) {
		V[key].push_back(data);
		if (key < mind) mind = key;
		if (key > maxd) maxd = key;
	}

	int top() { return mind; }
	T pop() {
		_update();
		T r = V[mind].back();
		V[mind].pop_back();
		return r;
	}
};

// ------------------------------------------------------------------------

int cse=1, seen[543];
int W[543][543], M[543][543],
	D[543];
vector<int> adj[543], pre[543];

void InfD(int n) { for (int i=0; i<n; ++i) D[i]=INF; }

void mark(int v) {
	for (int u: pre[v]) {
		M[u][v] = cse;
		if (seen[u]!=cse) {
			seen[u] =cse;
			mark(u);
		}
	}
}

IndexQueue<int> q;
bool dijkstra1(int n, int src, int dst) {
	InfD(n);
	q.clear();
	q.push(D[src]=0, src);
	while (!q.empty()) {
		int d = q.top(), u = q.pop();
		if (d != D[u]) continue;
		if (u == dst) {
			seen[dst] = cse;
			mark(dst);
			return 1;
		}

		for (int v: adj[u]) {
			int dd = d + W[u][v];
			if (dd < D[v]) {
				q.push(D[v]=dd, v);
				pre[v].clear();
				pre[v].push_back(u);
			}
			else if (dd == D[v])
				pre[v].push_back(u);
		}
	}
	return 0;
}

int dijkstra2(int n, int src, int dst) {
	InfD(n);
	q.clear();
	q.push(D[src]=0, src);
	while (!q.empty()) {
		int d = q.top(), u = q.pop();
		if (d != D[u]) continue;
		if (u == dst) return d;

		for (int v: adj[u]) if (M[u][v]!=cse) {
			int dd = d + W[u][v];
			if (dd < D[v])
				q.push(D[v]=dd, v);
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	for (int n,m; (n=readUInt()) && (m=readUInt()); ++cse) {
		int src = readUInt(),
			dst = readUInt();

		for (int i=0; i<n; ++i) {
			adj[i].clear();
			pre[i].clear();
		}

		for (int i=0; i<m; ++i) {
			int u = readUInt(),
				v = readUInt(),
				d = readUInt();
			
			adj[u].push_back(v);
			W[u][v] = d;
		}

		cout << (dijkstra1(n, src, dst) ? dijkstra2(n, src, dst) : -1) << endl;
	}
}
