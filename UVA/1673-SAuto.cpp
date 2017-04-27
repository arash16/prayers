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

inline int readStr(char *str) {
	char ch;
	while ((ch=readchar())==' ' || ch=='\n');
	if (ch == EOF) return 0;

	int l = 0;
	str[l++] = ch;
	while ((ch=readchar())!=' ' && ch!='\n' && ch!=EOF)
		str[l++] = ch;
	str[l] = 0;
	return l;
}

//---------------------------------------------------------------


class SuffixAutomaton {
	static const int SIGM = 11;
	vector<vector<int> > edges;  // edges[i]  : the labeled edges from node i
	vector<int> length;          // length[i] : the length of the longest string in the ith class
	vector<int> link;            // link[i]   : the parent of i
	int last;                    // the index of the equivalence class of the whole string
	int toId(char ch) { return ch-'0'; }

	public:
	void build(const char *s) {
		link.clear();
		edges.clear();
		length.clear();

		edges.push_back(vector<int>(SIGM, -1));
		link.push_back(-1);
		length.push_back(0);
		last = 0;

		for (int i=0, id; (id=toId(s[i]))>=0 && id<SIGM; i++) {
			edges.push_back(vector<int>(SIGM, -1));
			length.push_back(i+1);
			link.push_back(0);
			int r = edges.size() - 1;

			// add edges to r and find p with link to q
			int p = last;
			while (p >= 0 && edges[p][id]==-1) {
				edges[p][id] = r;
				p = link[p];
			}
			if (p != -1) {
				int q = edges[p][id];
				if (length[p] + 1 == length[q]) {
					// we do not have to split q, just set the correct suffix link
					link[r] = q;
				} else {
					// we have to split, add q'
					edges.push_back(edges[q]); // copy edges of q
					length.push_back(length[p] + 1);
					link.push_back(link[q]); // copy parent of q
					int qq = edges.size()-1;
					// add qq as the new parent of q and r
					link[q] = qq;
					link[r] = qq;
					// move short classes pointing to q to point to q'
					while (p >= 0 && edges[p][id] == q) {
						edges[p][id] = qq;
						p = link[p];
					}
				}
			}
			last = r;
		}
	}

	int oid;
	vector<int> ord;
	vector<bool> seen;
	void topo(int u) {
		for (int i=0, v; i<=10; ++i)
			if ((v=edges[u][i])!=-1 && !seen[v]) {
				seen[v] = 1;
				topo(v);
			}
		ord[--oid] = u;
	}

	int sumUnique() {
		int sz = oid = edges.size();
		seen.resize(sz);
		ord.resize(sz);
		for (int i=0; i<sz; ++i)
			seen[i] = 0;
		seen[0] = 1;
		topo(0);

		int result = 0;
		vector<int> sum(sz), 
					ins(sz);
					ins[0] = 1;
		for (int i=0; i<sz; ++i) {
			int u = ord[i];
			result = (result + sum[u]) % 2012;
			for (int v, j=u==0; j<10; ++j)
				if ((v=edges[u][j])!=-1) {
					ins[v] = (ins[v] + ins[u]) % 2012;
					sum[v] = (sum[v] + sum[u]*10 + ins[u]*j) % 2012;
				}
		}
		return result;
	}
} sa;

char s[200043];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int n;
	while ((n=readUInt())!=EOF) {
		int l = 0;
		for (int i=0; i<n; ++i) {
			int ll = readStr(s + l);
			s[l + ll++] = ':';
			l += ll;
		}
		s[l] = 0;

		sa.build(s);
		cout << sa.sumUnique() << endl;
	}
}
