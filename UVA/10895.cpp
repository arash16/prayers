#include <stdio.h>
#include <cstring>

#define MAXN 10017
short deg[MAXN], adj[MAXN][MAXN], mat[MAXN][MAXN], ind[MAXN], off[MAXN];

int main(){
	int n, m, d, x, y;
	while (scanf("%d%d", &n, &m)==2) {
		memset(deg, 0, m*sizeof(short));
		for (int i=0; i<n; ++i) {
			scanf("%d", &d);
			for (int j=0; j<d; ++j) {
				scanf("%d", &x);
				ind[j] = --x;
				off[j] = deg[x]++;
				adj[x][off[j]] = i;
			}

			for (int j=0; j<d; ++j) {
				scanf("%d", &y);
				mat[ind[j]][off[j]] = y;
			}
		}
		
		printf("%d %d\n", m, n);
		for (int i=0; i<m; ++i) {
			printf("%d", deg[i]);
			for (int j=0; j<deg[i]; ++j)
				printf(" %d", adj[i][j]+1);
			putchar('\n');
			if (deg[i]) {
				printf("%d", mat[i][0]);
				for (int j=1; j<deg[i]; ++j)
					printf(" %d", mat[i][j]);
			}
			putchar('\n');
		}
	}
}
