#include <stdio.h>
#include <cstring>
#include <iostream>
#include <bitset>
#include <queue>
#include <list>
using namespace std;

int n;
list<int> adj[101];
bitset<101> D[101];
bool inside[101], 
	 seen[101];

void dfs(int u) {
	bool first = !seen[u];
	inside[u]=1;
	seen[u]=1;
	D[u].set(u);
	for (int v: adj[u]) 
		if (!inside[v]) {
			if (!seen[v]) {
				D[v] = D[u];
				dfs(v);
			}
			else {
				bitset<101> bb = D[v] & D[u];
				bb.set(v);
				if (bb != D[v]) {
					D[v] = bb;
					dfs(v);
				}
			}
		}
	inside[u]=0;
}


void printDash() {
	putchar('+');
	for (int i=0; i<2*n-1; i++)
		putchar('-');
	puts("+");
}

int main(){
	int T, x;
	cin >> T;
	for (int cse=1; cse<=T; cse++) {
		cin >> n;
		for (int i=0; i<n; i++) {
			adj[i].clear();
			D[i].reset();
			seen[i] = 0;
			for (int j=0; j<n; j++) {
				cin>>x;
				if (x) adj[i].push_back(j);
			}
		}

		dfs(0);

		printf("Case %d:\n", cse);
		printDash();
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				putchar('|');
				putchar(D[j][i] ? 'Y' : 'N');
			}
			puts("|");
			printDash();
		}
	}
}
