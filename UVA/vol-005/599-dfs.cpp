#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

bool seen[26];
int mat[26][26];
char adj[26][26], deg[26];
void dfs(char u) {
	seen[u] = 1;
	for (int i=0; i<deg[u]; ++i)
		if (!seen[adj[u][i]])
			dfs(adj[u][i]);
}

int main(){
	int T;
	char line[1000];
	scanf("%d", &T);
	while (getchar()!='\n');
	for (int cse=1; cse<=T; ++cse) {
		memset(deg,0,sizeof(deg));
		while (gets(line) && line[0]!='*') {
			char u=line[1]-'A', v=line[3]-'A';
			if (mat[u][v] != cse) {
				adj[u][deg[u]++] = v;
				adj[v][deg[v]++] = u;
				mat[u][v] = cse;
			}
		}

		gets(line);
		int acn=0, tcn=0;
		memset(seen,0,sizeof(seen));
		for (int i=0; ; i+=2) {
			char u = line[i]-'A';
			if (!deg[u]) ++acn;
			else if (!seen[u]) {
				dfs(u);
				++tcn;
			}
			if (!line[i+1]) break;
		}

		printf("There are %d tree(s) and %d acorn(s).\n", tcn, acn);
	}
}
