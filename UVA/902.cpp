#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int diffs = 0;
struct Node {
	int cnt, cse;
	Node* adj[26];
	Node(): cse(0),cnt(0) {
		memset(adj, 0, sizeof(adj));
	}
	~Node() {
		for (int i=0; i<26; i++)
			if (adj[i])
				delete adj[i];
	}
};

char line[1000000];
int main(){
	int n;
	Node *root = new Node();
	for (int cse=1; scanf("%d%s", &n, line)==2; cse++) {
		int mxc=0, mxi=0;
		bool sht = 0;
		for (int s=0; line[s+n-1]; s++) {
			Node *p = root;
			for (int i=s; i<s+n; i++) {
				char ch = line[i] - 'a';
				if (ch<0) { sht=1; break; }

				if (!p->adj[ch])
					p->adj[ch] = new Node();
				p = p->adj[ch];
			}
			if (sht) break;

			if (p->cse != cse) {
				p->cse = cse;
				p->cnt = 1;
			}
			else if (++p->cnt > mxc) {
				mxc = p->cnt;
				mxi = s;
			}
		}

		line[mxi+n] = 0;
		puts(line + mxi);
	}
}
